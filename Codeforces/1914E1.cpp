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
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      vector<pair<ll, int>>a(n), b(n);
      for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
      }

      for(int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
      }

      vector<int>p(n);
      iota(p.begin(), p.end(), 0);

      sort(p.begin(), p.end(), [&] (int l, int r) {
        return a[l].first + b[l].first > a[r].first + b[r].first;
      });
      ll alice = 0, bob = 0;
      for(int i = 0; i < n; ++i) {
        if (i & 1) {
          bob += b[p[i]].first - 1;
        } else {
          alice += a[p[i]].first - 1;
        }
      }
      // cout << "ans DABA ";
      cout << alice - bob << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
