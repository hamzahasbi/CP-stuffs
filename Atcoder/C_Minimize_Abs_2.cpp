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
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
set<ll>perf;


ll closestSquare(ll left, ll right, ll D) {
    ll ans = left;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (mid * mid <= D) {
          // cout << mid << endl;
          ans = mid;
          left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    ll D;
    cin >> D;
    for(ll i = 0LL; i * i <= D; ++i) {
      perf.insert(i * i);
    }
    ll ans = LLONG_MAX;
    for(auto el : perf) {
      auto curr = perf.upper_bound(D - el);
      auto lb = perf.lower_bound(D - el);
      if (lb != perf.end()) ans = min(ans, abs((el + *lb) - D));
      curr--;
      // cout << el << " " << *curr << endl;
      // cout << el.first << " " << closestSquare(D - el.first) << endl;
      ans = min(ans, abs((el + *curr) - D));
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}

