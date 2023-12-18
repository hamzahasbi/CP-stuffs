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
inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline long long lcm(ll a,ll b) {return a * b / gcd(a,b);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}

bool isSubsetSumPossible(long long bitmask, int target) {
    for (int i = 0; i <= 29; ++i) {
        if ((bitmask >> i) & 1LL) {
            long long sum = target - i;
            if (sum >= 0 && sum <= 29 && ((bitmask >> sum) & 1LL)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int m;
    cin >> m;
    vector<int>mp(31, 0);
    while(m--) {
      ll t, x;
      cin >> t >> x;
      if (t == 1) {
        mp[x]++;
        for (int i = 0; i < 30; ++i) if (mp[i] == 3) {
            mp[i] = 1;
            mp[i + 1] += 1;
        }
      } else {
        for (int i = 29; i >= 0; --i) {
          for (int j = 0; j < mp[i]; ++j) {
            if (x >= (1LL << i)) {
              x -= 1LL << i;
            }
          }
        }
        if (x == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
      }

    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
