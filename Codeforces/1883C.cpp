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
#define MAX_VALUE 100000
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
unordered_map<int, set<int>>pre;

void generate(int p) {
  int i = 1;
  int mult = p;
  while(mult <= MAX_VALUE) {
    mult = p * i ;
    pre[p].insert(mult);
    ++i;
  }
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    for(int i = 2; i <= 5; ++i) {
      generate(i);
    }
    int t;
    cin >> t;
    while(t--) {
      int n,k;
      cin >> n >> k;
      map<int, int>a;
      int even = 0;
      long long p = 1;
      for(int i = 0; i < n; ++i) {
        int _;
        cin >> _;
        p *= _;
        if (!(_ & 1)) even++;
        a[_]++;
      }
      int mn = INT_MAX;
      if (k != 4) {
        for(auto el : a) {
          auto r = pre[k].lower_bound(el.first);
          // auto l = r;
          // l = l != pre[k].begin() ? --l : l;

          int localMin = (*r - el.first);
          mn = min(localMin, mn);
        }
      } else {
        // we need at least 2 even numbers

        if (n >= 2 && p % k) {
          if (a[7] || a[3]) mn = 1;
          else mn = max(0, 2 - even);
        } else {
          mn = 0;
        }
      }
      cout << mn << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
