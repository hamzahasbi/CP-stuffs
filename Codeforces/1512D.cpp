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
        vector<long long>b(n + 2);
        for(int i = 0; i < n + 2; ++i) {
            cin >> b[i];
        }
        sort(b.begin(), b.end());

        long long sum = accumulate(b.begin(), b.begin() + n, 0LL);
        bool solution = b[n] == sum;
        if (solution) {
            for(int i = 0; i < n; ++i) {
                cout << b[i] << ' ';
            }
            cout << endl;
        } else {
            sum += b[n];
            for(int i = 0; i < n + 1; ++i) {
                if (sum - b[i] == b[n + 1]) {
                    for(int j = 0; j < n + 1; ++j) {
                        if (i != j) {
                            cout << b[j] << ' ';
                        }
                    }
                    cout << endl;
                    solution = true;
                    break;
                }
            }

            if (!solution) cout << -1 << endl;
        }
    }
    
    return 0;
}