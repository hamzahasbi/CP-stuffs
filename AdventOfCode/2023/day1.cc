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
   freopen("../io/input.in", "r", stdin);
   freopen("../io/output.out", "w", stdout);
  #endif
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string s;
    int ans = 0;
    unordered_map<string, char>digit;
    digit["one"] = '1';
    digit["two"] = '2';
    digit["three"] = '3';
    digit["four"] = '4';
    digit["five"] = '5';
    digit["six"] = '6';
    digit["seven"] = '7';
    digit["eight"] = '8';
    digit["nine"] = '9';
    while(cin >> s) {
      char l, r;
      l = '$', r = '$';
      string pl = "";
      bool can = false;
      for(auto el : s) {
        pl += el;
        for(auto n : digit) {
          if (pl.find(n.first) != string::npos) {
            // cout << "test Case " << pl << endl;

            can = true;
            if (l == '$') {
              l = n.second;
            }
            r = n.second;
            pl = el;
            break;
          }
        }
        if (isdigit(el)) {
          if (l == '$') {
            l = el;
          }
          r = el;
          pl = el;
        }
      }
      string ss = "";
      ss += l; ss+= r;
      ans += stoi(ss);
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
