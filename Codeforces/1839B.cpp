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
bool predicat(pair<long long, long long>a, pair<long long, long long>b) {
  if (a.first < b.first) return true;
  if (a.first == b.first && a.second > b.second) return true;
  return false;
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
      long long ans = 0;
      vector<pair<long long, long long>>lamp(n);
      map<long long, vector<long long>>f;
      for(int i = 0; i < n; ++i) {
        cin >> lamp[i].first >> lamp[i].second;
        f[lamp[i].first].push_back(lamp[i].second);
      }

      // sort(lamp.begin(), lamp.end(), predicat);
      // for(int i = 0; i < n; ++i) {
      //   cout << lamp[i].first << " " << lamp[i].second << endl;
      // }
      for(int i = 1; i <= n; ++i) {
        auto scores = f[i];
        sort(scores.rbegin(), scores.rend());
        auto taken = i;
        for(auto score : scores) {
          if (taken == 0) break;
          taken -= 1;
          ans += score;
        }
      }
      cout << ans << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
