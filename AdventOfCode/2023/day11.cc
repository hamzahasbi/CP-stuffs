/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
//inline long long lcm(ll a,ll b) {return a * b / __gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("../../io/input.in", "r", stdin);
  //  freopen("../../io/output.out", "w", stdout);
  #endif
}

bool isValid(int i, int j, int n, int m) {
  return (i >= 0 && i < n && j >= 0 && j < m);
}

long long Manhattan(vector<pair<ll,ll>>points) {
  long long ans = 0;
  for (int i = 0; i < points.size(); ++i) {
      for(int j = i + 1; j < points.size(); ++j) {
        ans += (llabs(points[j].first - points[i].first) + llabs(points[j].second - points[i].second)) ;
      }
  }
  return ans;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    vector<string>grid, extended, inversed;

    int n, m;
    string line;
    vector<pair<ll, ll>>galaxy;

    while(cin >> line) {
      grid.push_back(line);
    }
    n = grid.size();
    m = grid[0].size();
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if (grid[i][j] == '#') {
          galaxy.push_back({i, j});
        }
      }
    }
    int offset = 1000000;
    // Empty Rows
    for(int i = n - 1; i >= 0; --i) {
      auto empty = grid[i].find("#");
      if (empty == string::npos) {
        for(auto &gal : galaxy) {
          if (gal.first > i) {
            gal.first += offset - 1;
          }
        }
      }
    }
    // Empty Columns
    for(int j = m - 1; j >= 0; --j) {
      string col = "";
      for(int i = 0; i < n; ++i) {
        col += grid[i][j];
      }
      auto empty = col.find("#");
      if (empty == string::npos) {
        for(auto &gal : galaxy) {
          if (gal.second > j) {
            gal.second += offset - 1;
          }
        }
      }
    }
    // Part 1 brute force.
    // n = grid.size();
    // for(int i = 0; i < n; ++i) {
    //   for(int j = 0; j < m; ++j) {
    //     if (extended[i][j] == '#') {
    //       galaxy.push_back({i, j});
    //     }
    //   }
    // }
    // for(int j = 0; j < m; ++j) {
    //   string newLine = "";
    //   for(int i = 0; i < grid.size(); ++i) {
    //     newLine += grid[i][j];
    //   }
    //   inversed.push_back(newLine);
    //   if (newLine.find("#") == string::npos) {
    //     inversed.push_back(newLine);
    //   }
    // }
    // for(int j = 0; j < inversed[0].size(); ++j) {
    //   line = "";
    //   for(int i = 0; i < inversed.size(); ++i) {
    //     line += inversed[i][j];
    //   }
    //   extended.push_back(line);
    // }


    // map<pair<int,int>, int>dis;
    // for(int k = 0; k < galaxy.size(); ++k) {
    //   pair<int, int>root = galaxy[k];
    //   dis.clear();
    //   queue<pair<int,int>>q;
    //   q.push(root);
    //   dis[root] = 0;
    //   int depth = 0;
    //   while(!q.empty()) {
    //     auto v = q.front();
    //     q.pop();
    //     for(int dx = -1; dx <= 1;  ++dx) {
    //       for(int dy = -1; dy <= 1; ++dy) {
    //         if (abs(dx) == abs(dy)) continue;
    //         int x = v.first + dx;
    //         int y = v.second + dy;
    //         if (!isValid(x, y, n, m)) continue;
    //         if (!dis.count({x, y})) {
    //           dis[{x, y}] = dis[v] + 1;
    //           q.push({x, y});
    //         }
    //       }
    //     }
    //   }
    //   for(int r = k + 1; r < galaxy.size(); ++r) {
    //     auto to = galaxy[r];

    //     ans += dis[to];
    //   }
    // }
    cout << Manhattan(galaxy) << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
