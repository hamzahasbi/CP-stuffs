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
bool valid(int i, int n) {
  return (i - 1 >= 0 && i + 1 < n );
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n, k;
    cin >> n >> k;
    int last = 0;
    n <<= 1;
    n++;
    vector<int>a(n), peaks;

    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] > last && i > 0) {
        peaks.push_back(i);
      }
      last = a[i];
    }
    // cout << peaks.size() << endl;
    for(int i = 0; i < peaks.size() && k > 0; ++i) {
      if (peaks[i] % 2 == 0) {
        a[peaks[i]]--;
        k--;
      } else if (valid(peaks[i], n)) {
        // cout << a[peaks[i] - 1] << " " << a[peaks[i] + 1] << endl;
        if ((a[peaks[i]] - 1 > a[peaks[i] - 1]) && (a[peaks[i]] - 1 > a[peaks[i] + 1])) {
          a[peaks[i]]--;
          k--;
        }

      }
    }
    for(auto p : a) {
      cout << p << " ";
    }
    cout << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
