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

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;

    while(cin >> n) {
      if (n == -1) return 0;
      set<int>ans;
      vector<vector<int>>graph;
      graph.resize(n, vector<int>(n));
      for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
          cin >> graph[i][j];
        }
      }

      for(int i = 0; i < n; ++i) {
        bool canTriangle = false;
        for(int j = 0; j < n; ++j) {
          auto cell = graph[i][j];
          if (i == j) continue;
          if (cell == 1) {
            for(int k = 0; k < n; k++) {
              if (k == j) continue;
              auto subcell = graph[j][k];
              if(subcell == 1) {
                canTriangle |= (graph[k][i] == 1);
              }
            }
          }
        }
        if (!canTriangle) {
          ans.insert(i);
        }
      }
      for(auto el : ans) {
        cout << el << " ";
      }
      cout << endl;

    }
    return 0;
}
