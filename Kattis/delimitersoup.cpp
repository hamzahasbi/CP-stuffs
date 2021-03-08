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
    int l;
    cin >> l;
    string sequence;
    module;
    getline(cin, sequence);
    vector<pair<char, int>>validator;
    map<char, char>match;
    match['('] = ')';
    match['['] = ']';
    match['{'] = '}';

    for(int i = 0; i < l; ++i) {
        if (sequence[i] == ' ') continue;
        if (!validator.size()) validator.push_back({sequence[i], i});
        else {
            auto curr = sequence[i];
            if (!match.count(curr)) {
                if (match.count(validator.back().first) && curr == match[validator.back().first]) {
                    validator.pop_back();
                } else validator.push_back({curr, i});
            } else validator.push_back({curr, i});
        }
    }


    for(auto &el : validator) {
        // cout << !match.count(el.first) << endl;
        if (!match.count(el.first)) {
            cout << el.first << " " << el.second << endl;
            return 0;
        }
    }

    cout << "ok so far" << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}