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
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e');
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
      string s;
      cin >> s;
      vector<string> syllables;
      while (!s.empty())
          if (s.back() == 'a' || s.back() == 'e') {
              syllables.push_back(s.substr(s.size() - 2));
              s.resize(s.size() - 2);
          } else {
              syllables.push_back(s.substr(s.size() - 3));
              s.resize(s.size() - 3);
          }
      reverse(syllables.begin(), syllables.end());

      for (int i = 0; i < syllables.size(); i++) {
          if (i > 0) cout << '.';
          cout << syllables[i];
      }

      cout << '\n';
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
