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
#define LONG_N 1000000000000000001
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
    unsigned long long k;
    cin >> n >> k;
    vector<unsigned long long>dp(3, 0);
/* Fibonacci is the length of the string at each step */
    dp[1] = 1;
    dp[2] = 1;
    /* 1000000000000000001 to prevent overflow => It is guaranteed that
      is at most the length of the N-th string in the Batmanacci sequence.
    */
    for(int i = 3; i <= n; ++i) {
      dp.push_back( min((ull) LONG_N, dp[i - 2] + dp[i - 1]));
    }
    int j = n;
    while(j > 2) {
      if (k > dp[j - 2]) {
        k -= dp[j - 2];
        j--;
      } else j -= 2;
    }
    puts(j == 1 ? "N" : "A");
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
