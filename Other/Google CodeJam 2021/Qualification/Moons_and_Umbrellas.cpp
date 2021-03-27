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
        int t;
        cin >> t;
        for(int tt = 1; tt <= t; ++tt) {
            int ans = 0;
            int x, y;
            string s;
            cin >> x >> y >> s;


            for(int i = 0; i < s.size(); ++i) {
                if (s[i] == '?') {
                    char l = i >= 1 ? s[i - 1] : '*';
                    int j = i + 1;
                    while(j < s.size() && s[j] == '?') {
                        if (s[j] != '?') break;
                        j++;
                    }
                
                    for(; i < j && i < s.size(); ++i) s[i] = l;
                    // i = j;
                }
                
            }
            // cout << s << endl;
            for(int i = 0; i < s.size() - 1; ++i) {
                if (s[i] == 'C' && s[i + 1] == 'J') ans += x;
                else if (s[i] == 'J' && s[i + 1] == 'C') ans += y;
            }
            
            printf("Case #%d: %d\n", tt, ans);

        }
        // auto end = std::chrono::high_resolution_clock::now();
        // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
        // cout << "Finished in " << duration << " ms" << endl;
        return 0;
    }