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
vector<tuple<int,int, string>>go (int i, int j, char c, string to) {
  vector<tuple<int,int, string>> dir;
  switch(c){
    case '|':
      if (to == "right" || to == "left") {
        dir.push_back({i - 1, j, "top"});
        dir.push_back({i + 1, j, "down"});
      }
      else {
        if (to == "top") {
          dir.push_back({i - 1, j, to});
        } else {
          dir.push_back({i + 1, j, to});
        }
      }
      break;
    case '-':
      if (to == "top" || to == "down") {
        dir.push_back({i, j - 1, "left"});
        dir.push_back({i, j + 1, "right"});
      }
      else {
        if (to == "right") {
          dir.push_back({i, j + 1, to});
        } else {
          dir.push_back({i, j - 1, to});
        }
      }
      break;
    case '/':
      if (to == "right") dir.push_back({i - 1, j, "top"});
      if (to == "left") dir.push_back({i + 1, j, "down"});
      if (to == "top") dir.push_back({i, j + 1, "right"});
      if (to == "down") dir.push_back({i, j - 1, "left"});
      break;
    case '\\':
      if (to == "left") dir.push_back({i - 1, j, "top"});
      if (to == "right") dir.push_back({i + 1, j, "bottom"});
      if (to == "down") dir.push_back({i, j + 1, "right"});
      if (to == "top") dir.push_back({i, j - 1, "left"});
      break;
    case '.':
      if (to == "left") dir.push_back({i, j - 1, "left"});
      if (to == "right") dir.push_back({i, j + 1, "right"});
      if (to == "down") dir.push_back({i + 1, j, "down"});
      if (to == "top") dir.push_back({i - 1, j, "top"});
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
    int n = 0, m = 0;
    while(cin >> s) {
      grid.push_back(s);
      m = (int) s.size();
    }
    n = grid.size();

    set<pair<int, int>> energized;
    queue<tuple<int, int, string>> q;

    q.push({0, 0, "right"});

    while (!q.empty()) {
        auto vertice = q.front();
        q.pop();

        int x = get<0>(vertice);
        int y = get<1>(vertice);
        string direction = get<2>(vertice);

        if (energized.count({x, y}) || !isValid(x, y, n, m)) {
            continue;
        }

        energized.insert({x, y});

        auto neighbors = go(x, y, grid[x][y], direction);
        for (auto path : neighbors) {
            int newX = get<0>(path);
            int newY = get<1>(path);
            string newD = get<2>(path);
            q.push({newX, newY, newD});
        }
    }

    cout << energized.size() << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
