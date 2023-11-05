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
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      vector<int>a(n);
      for(int i = 0; i < n; ++i) {
        cin >> a[i];
      }
      int l = 0, r = n - 1;
      int alice = 0, bob = 0, moves = 0;
      int last = -1, curr = 0;
      bool f = true;
      while(l <= r) {
        if (f) {
          alice += a[l];
          curr += a[l];
          l++;
        } else {
          bob += a[r];
          curr += a[r];
          r--;
        }
        if (curr > last || l > r) {
          last = curr;
          curr = 0;
          moves += 1;
          f = !f;
        }
      }
      // cout << l << " " << r << endl;
      cout << moves << " " << alice << " " << bob << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
