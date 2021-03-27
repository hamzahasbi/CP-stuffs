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


int solve(vector<int> a) {
    int ans = 0;
    for(int i = 0; i < a.size(); ++i) {
        int mn_index = min_element(a.begin() + i, a.end()) - a.begin();
        
        // cout << i + 1 << " " << mn_index + 1 << endl;
        ans += (mn_index - i + 1);
        reverse(a.begin() + i, a.begin() + mn_index + 1);
        // print(a);
    }
    return ans - 1;
}


int main() {
    // auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt) {

        long long ans = 0;
        int n, c;
        cin >> n >> c;
        vector<int>a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
        printf("Case #%d: ", tt);


        bool f = false;
        do {
            if (solve(a) == c) {
                for(int i = 0; i < n; ++i) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
                f = true;
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
        
        if (!f) {
            printf("IMPOSSIBLE\n");
        }
        
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}