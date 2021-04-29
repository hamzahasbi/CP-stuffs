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

long long solve(int from, int to, vector<int> a, int k) {
    vector<int>found(k + 1, 0);
    for(int i = from; i <= to; ++i) {
        found[a[i]] += 1;
    }
    long long ans = 1LL;

    for(int i = 1; i <= k; ++i) {
        ans *= (1LL << (found[i])) - 1;
    }
    return ans;
     
}
int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << solve(0, n - 1, a, k) << endl;

    return 0;
}