/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
template <class T> void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }
inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline long long lcm(ll a,ll b) {return a * b / gcd(a,b);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
bool canMakeBeautifulTree(int X, int Y, int N) {
    int maxLeavesLarge = X / 2; // Each large ornament decorates 2 leaves
    int maxLeavesSmall = Y / 3; // Each small ornament decorates 3 leaves

    // To make a leaf beautiful, it requires either 1 large ornament and 3 small ornaments
    // or 2 large ornaments.
    // Check if we have enough ornaments for the given number of leaves
    return min({maxLeavesLarge, maxLeavesSmall, N}) >= N;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int t;
    cin >> t;
    while(t--) {
      ll n, x, y;
      cin >> n >> x >> y;
      ll Y = y / 3;
      ll rx = max(0LL, x - Y);
      ll X = rx / 2;

      if (x/ 2 >= n || (rx == 0 && Y >= n && x >= n) || (Y > 0 && rx > 0 && X + Y >= n)) puts("YES");
      else puts("NO");
      // ll k = x - n;
      // if (k == 0) cout << "NO\n";
      // else {
      //   ll c = y / (3);
      //   if (c >= n) {
      //     cout << "YES\n";
      //   } else {
      //     ll z = x / (2);
      //     if (z >= n) {
      //       cout << "YES\n";
      //     } else {
      //       cout << n << " "<< c << " " << z << endl;
      //       ll p = (x - c) / 2;
      //       if ((x - c) > 0 && p + c >= n) {
      //         cout << "YES\n";
      //       } else cout << "NO\n";
      //     }
      //   }
      // }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
