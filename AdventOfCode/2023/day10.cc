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

vector<pair<int,int>>go (int i, int j, char c) {
  vector<pair<int,int>> dir;
  switch(c){
    case '|':
      dir.push_back({i + 1, j});
      dir.push_back({i - 1, j});
      break;
    case '-':
      dir.push_back({i, j + 1});
      dir.push_back({i, j - 1});
      break;
    case 'L':
      dir.push_back({i - 1, j});
      dir.push_back({i, j + 1});
      break;
    case 'J':
      dir.push_back({i - 1, j});
      dir.push_back({i, j - 1});
      break;
    case '7':
      dir.push_back({i + 1, j});
      dir.push_back({i, j - 1});
      break;
    case 'F':
      dir.push_back({i + 1, j});
      dir.push_back({i, j + 1});
      break;
  }
  return dir;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string s;
    int bet;
    vector<string>grid;
    int ans = 0LL;
    pair<int, int>root;
    int n = 0, m = 0;
    while(cin >> s) {
      grid.push_back(s);
      auto pos = s.find("S");
      if (pos != string::npos) {
        root = {n, pos};
      }
      m = (int) s.size();
      ++n;
    }
    map<pair<int,int>, int>dis;
    queue<pair<int, int>>q;
    dis[root] = 0;
    // cout << root.first << " " << root.second << endl;
    q.push(root);
    while(!q.empty()) {
      auto vertice = q.front();
      q.pop();

      int x = vertice.first;
      int y = vertice.second;
      for(int dx = -1; dx <= 1; dx++) {
        for(int dy = -1; dy <= 1; ++dy) {
          if (abs(dx) == abs(dy)) continue;
          int x = vertice.first + dx;
          int y = vertice.second + dy;
          if (isValid(x, y, n, m) && !dis.count({x, y})) {
            if (grid[x][y] == '.' || grid[x][y] == 'S') continue;
            auto neighbors = go(x, y, grid[x][y]);
            for(auto path : neighbors) {
              if (path == vertice) {
                // cout << "Momkine " << grid[x][y] << " ila " << path.first << " " << path.second << endl;
                dis[{x, y}] = 1 + dis[vertice];
                q.push({x, y});
              }
            }
          }
        }
      }
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if (dis.count({i, j})) {
          // cout << dis[{i, j}] << " ";
          ans = max(ans, dis[{i, j}]);
        } else {
          // cout << ". ";
        }
      }
      // cout << endl;
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
