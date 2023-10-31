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
      int n, q, x;
      cin >> n >> q;
      unordered_map<int, bool>mp;
      vector<long long> a(n), b;
      for(int i = 0; i < n; ++i) {
        cin >> a[i];
      }

      for(int i = 0; i < q; ++i) {
        cin >> x;
        if (!mp.count(x)) {
          mp[x] = true;
          b.push_back(x);
        }
      }
      for(auto el : b) {
        x = (1 << el);
        for(int i = 0; i < n; ++i) {
          if (a[i] % x == 0) {
            // cout << "Changed" << endl;
            // cout << el.first << " => "  << (1 << el.first) << " " << el.second << endl;
            a[i] += x / 2;
          }
        }
      }

      for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
      }
      cout << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
