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

ull powlog(ull a, int x) {

  if (x == 0) return 1LL;
  if (x == 1) return a;
  ull val = powlog(a, x / 2);
  if (x & 1) {
    return val * val * a;
  } else {
    return val * val;
  }
}



int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    vector<ull>p(19, 0);
    ull offset = -1;
    p[1] = 9;
    for(int i = 2; i <= 18; ++i) {
      // offset = p[i - 1] - 1;
      p[i] = ((powlog(10, i)) - powlog(10, i - 1)) * i;
      p[i] += (p[i - 1]);
      // cout << p[i] << endl;
    }
    // cout << "------" << endl;
    // return 0;
    // 1234567891011121314
    int q;
    cin >> q;
    while(q--) {
      ull k;
      cin >> k;
      if (k <= 9) {
        cout << k << endl;
        continue;
      }
      auto ff = lower_bound(p.begin(), p.end(), k) - p.begin();
      // cout << ff << endl;

      string s = "1";
      while(s.size() < ff) {
        s += '0';
      }
      ull l = max(ff - 1LL, 1LL) , r = p[l];
      ull pos = k - r - 1LL;
      ull off = pos / ff;
      ull number = stoll(s) + off;
      s = to_string(number);
      // cout << "length shifted "  << s << endl;
      cout << s[pos % ff] << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
