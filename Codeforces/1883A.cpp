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

int cost (int from, int to) {
  if (from == 9 && from != to) return 9 - to;
  return abs(to - from);
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int t;
    cin >> t;
    string ref = "1234567890";
    while(t--) {
      string s;
      cin >> s;
      int l = 0, r = 0;
      int step = 0;
      for(int i = 0; i < 4; ++i) {
        // Go right
        auto curr = ref.find(s[i]);
        auto last = i == 0 ? 0 : ref.find(s[i - 1]);
        // cout << curr << " " << last << " " << cost(last, curr) << endl;
        // Go left
        step += cost(last, curr) + 1;
        last = curr;
      }
      cout << step << endl;

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
