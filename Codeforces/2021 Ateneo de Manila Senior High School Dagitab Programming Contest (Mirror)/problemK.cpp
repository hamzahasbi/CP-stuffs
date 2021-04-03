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
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n;
    cin >> n;
    vector<long long>a(n);
    unordered_map<long long, bool>isHere;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long mx = *max_element(a.begin(), a.end());
    for(int i = 1; i * i <= mx; ++i) {
        if (mx % i == 0) {
            isHere[i] = true;
            isHere[mx / i] = true;
        }
    }
    bool found = true;
    int pos = -1;
    for(int i = 0; i < n; ++i) {
        // cout << a[i] << " " << found << endl;
        found &= isHere[a[i]];
        if (a[i] == mx && pos == -1) pos = i + 1;
    }
    // cout << mx << " " << found << endl;
    if (!found) cout << -1 << endl;
    else cout << pos << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}