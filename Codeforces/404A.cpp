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
    int n;
    cin >> n;
    vector<string>a(n);
    map<char,int>mp;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      for(auto el : a[i]) {
        mp[el]++;
      }
    }
    if (mp.size() > 2) {
      cout << "NO\n";
    } else {
      char must = a[0][0];
      bool can = true;
      for(int i = 0; i < n; ++i) {
        can &= must == a[i][i];
        can &= must == a[i][n - i - 1];
        for(int j = 0; j < n; ++j) {
          if (j == i || j == n - i - 1) continue;
          can &= a[i][j] != must;
        }
      }
      puts(can ? "YES" : "NO");
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
