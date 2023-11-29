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
set<int>mult(int n) {
  set<int>ss;
  int i = 1;
  while(n <= 5000) {
    ss.insert(n * i);
    ++i;
  }
  return ss;
}

set<int>div(int n) {
  set<int>ss;
  for(int i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      ss.insert(i);
      ss.insert(n / i);
    }
  }
  return ss;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int t;
    cin >> t;
    while(t--) {
      int a, b;
      cin >> a >> b;
      if (a % b == 0) {
        cout << 0 << endl;
        continue;
      }
      int aa = a + b - 1, bb = 1;
      int ans1 = 0;
      int ans2 = 0;
      int ans = b - 1;
      while(aa > a) {
        // cout << aa << " " << bb << "---- " << aa - a << endl;
        if (aa % bb == 0) {
          ans = min(ans, aa - a);
        }
        aa--;
        bb++;
      }
      aa = 1, bb = a + b - 1;
      while(bb > b) {
        // cout << aa << " " << bb << "---- " << aa - a << endl;
        if (aa % bb == 0) {
          ans = min(ans, bb - b);
        }
        aa++;
        bb--;
      }
      cout << ans << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}

