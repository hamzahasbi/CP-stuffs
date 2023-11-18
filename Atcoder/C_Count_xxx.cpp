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
    int n;
    cin >>n;
    string s;
    cin >> s;
    map<char, vector<int>>mp;
    int ans, cc;
    ans = cc = 1;
    ans = 0;
    for(int i = 0; i < n; ++i) {
     mp[s[i]].push_back(i);
    }

    for(char c = 'a'; c <= 'z'; ++c) {
      if (!mp.count(c)) continue;
      cc = 1;
      auto last = mp[c].front();
      auto mx = -1;
      for(int i = 1; i < mp[c].size() ;++i) {
        auto el = mp[c][i];
        if (abs(el - last) == 1) {
          cc++;
        } else {
          mx = max(mx, cc);
          cc = 1;
        }
        last = el;
      }
      mx = max(mx, cc);
      // cout << c << " " << mx << endl;
      ans += mx;
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
