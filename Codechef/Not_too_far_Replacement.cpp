/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
#endif
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
template<typename T> void printVector(const T& t) {
copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, " "));
cout << "\n";
}
template<typename T> void printVectorInVector(const T& t) {
for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}
void _print() {cout << "]\n";}
template<typename T> void _print(const T &x) {cout << x;}
template<typename T, typename... Args>
void _print(const T &x, const Args &... args) {cout << x << ", "; _print(args...);}
#ifndef ONLINE_JUDGE
#define debug(x...) do { cout << "[" << #x << "] = ["; _print(x); _print();} while(0)
#else
#define debug(x...)
#endif
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    READ();
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      vector<int> a(n + 1);
      for(auto &el : a) cin >> el;
      int ans = accumulate(a.begin(), a.begin() + n, 0);
      int r_bound = *max_element(a.begin(), a.end());
      int c  = 0;
      while(true) {
        int target = 2 * a.back();
        int l_bound = -1, l_b = -1;
        for(int i = 0; i < n; i++) {
          if (a[i] <= target && a[i] > a.back()) {
            if (l_bound <= a[i]) {
              l_b = i;
              l_bound = a[i];
            }
          }
        }
        if (l_b != -1) {
          swap(a[l_b], a[n]);
        } else {
          break;
        }
        ans = min(ans, accumulate(a.begin(), a.begin() + n, 0));
        // c++;
        if (a.back() == r_bound) break;
        // debug(l_bound, target, r_bound);
        // if (c >= n) break;
      }
      cout << ans << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
