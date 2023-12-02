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
string setContent(set<int> s) {
  string ret = "";
  for(auto el : s) {
    ret += ' ' + to_string(el);
  }
  return ret;
}
int width(int sz, int p) {
  return ceil(9 * p * sz * 1.0 / 16 );
}
int height(int f, int fM) {
  f -= 4;
  f *= 40;
  fM -= 4;
  return (8 + (ceil(f * 1.0 / fM)));
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int tt = 1;
    while(true) {
      int w, n;
      cin >> w >> n;
      if (w == 0 && n == 0) break;
      map<string, int> mp;
      int mx = 0;
      for(int i = 0; i < n; ++i) {
        string _s;
        int _oc;
        cin >> _s >> _oc;
        mp[_s] = _oc;
        mx = max(_oc, mx);
      }
      int curr = w;
      int cloud = 0, c = 0;
      unordered_map<int, set<int>>rows;
      for(auto el : mp) {
        int W, H;
        H = height(el.second, mx);
        W = width((int) el.first.size(), H);
        while(W > curr) {
          c++;
          rows[c].insert(H);
          curr = w;
          if(W >= w) {
            W -= w;
          }
          else break;
        }
        if (W > 0) {
          rows[c].insert(H);
          curr = curr - W;
        } else {
          curr = w;
        }
        curr -= 10;
        if (curr <= 0) {
          curr = w;
          c++;
        }
      }

      for(auto p : rows) {
        auto cl = p.second.rbegin();
        cloud += *cl;
      }
      cout << "CLOUD " << tt++ << ": " << cloud << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
