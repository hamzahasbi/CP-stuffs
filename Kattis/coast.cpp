/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
#define MAX 1001
//inline long long lcm(ll a,ll b) {return a * b / __gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}

int n, m;
vector<string>grid;
int vis[MAX][MAX];
unordered_map<int, vector<int>>cycles;


bool can(int i , int j) {
  if (i < 0 || j < 0 || i > n + 1 || j > m + 1) {
    return false;
  }
  if(grid[i][j] != '0') {
    return false;
  }
  return true;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({0,0});

    while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(grid[i][j] != '0') {
            continue;
        }
        grid[i][j] = 's';
        for(int dx = -1; dx <= 1; dx++) {
          for(int dy = -1; dy <= 1; dy++) {
            if (abs(dx) == abs(dy)) continue;
            auto newX = i + dx;
            auto newY = j + dy;

            if (can(newX, newY)) q.push({newX, newY});
          }
        }
    }
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    cin >> n >> m;
    string init = "";
    init.assign(m + 2, '0');
    grid.resize(n + 2, init);
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; j++)
        cin >> grid[i][j];
    }
    int borders = 0;
    bfs();
      // for(int i = 0; i <= n; ++i)
      //   cout << grid[i].size() << endl;


    for(int i = 1; i <= n; ++i) {
      // cout << grid[i] << endl;
      for(int j = 1; j <= m; ++j) {
        if (grid[i][j] == '1') {
          for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
              if (abs(dx) == abs(dy)) continue;
              auto newX = i + dx;
              auto newY = j + dy;
              // cout << newX << " " << newY << endl;
              if (grid[newX][newY] == 's') borders++ ;
            }
          }
        }
      }
    }
//
    cout << borders << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
