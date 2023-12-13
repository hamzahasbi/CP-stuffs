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
      vector<long long>a(n);
      map<long long, int>st;
      for(int i = 0; i < n; ++i) {
        cin >> a[i];
        st[a[i]]++;
      }

      long long sum = 0LL;
      int cursed = 0;
      bool f = false;
      vector<int64_t>ans;
      for(auto &el : st) {
        if (!f){
          ans.push_back(el.first);
          el.second--;
          sum += el.first;
          f = true;
          continue;
        }
        // cout << sum << endl;
        if (sum >= el.first) cursed++;
        else {
          ans.push_back(el.first);
          el.second--;
          sum += el.first;
        }
      }
      cursed = n - ans.size();
      cout << cursed << endl;
      for(auto &el : ans) {
        cout << el << " ";
      }
      for(auto &el : st) {
        while(el.second > 0) {
          cout << el.first << " ";
          el.second--;
        }
      }
      cout << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
