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
    int t;
    cin >> t;
    while(t--) {
      int n;
      cin >> n;
      vector<long long>a;
      priority_queue<long long, vector<long long>, greater<long long>>pq;

      for(int i = 0; i < n; ++i) {
        int _;
        cin >> _;
        a.push_back(_);
      }
      auto l = distance(a.begin(), min_element(a.begin(), a.end()));
      int ans = l;
      int j = l;
      for(; l < n; ++l) {
        pq.push(a[l]);
      }

      while(!pq.empty() && j < n) {
        auto curr = pq.top();
        pq.pop();
        if (a[j] != curr) {
          ans = -1;
          break;
        }
        j++;
      }
      cout << ans << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
