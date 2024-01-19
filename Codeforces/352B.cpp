/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
#endif
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
template<typename T> void printVector(const T& t) {
copy(t.cbegin(), t.cend(), ostream_iterator<typename T::value_type>(cout, " "));
cout << "\n";
}
template<typename T> void printVectorInVector(const T& t) {
for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}
void _print() {cout << "]\n";}
template<typename T> void _print(const T &x) {cout << x;}
template<typename T, typename... Args>
void _print(const T &x, const Args &... args) {cout << x << ", "; _print(args...);}
#ifndef ONLINE_JUDGE
#define debug(x...) do { cout << "[" << #x << "] = ["; _print(x); _print();} while(0)
#else
#define debug(x...)
#endif
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    READ();
    int n;
    cin >> n;
    map<int, vector<int>>mp;
    for(int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mp[a].push_back(i + 1);
    }
    vector<pair<int,int>>sol;
    for(auto x : mp) {
      if (x.second.size() == 1) {
        sol.push_back({x.first, 0});
        continue;
      }
      int d = x.second[1] - x.second[0];
      int sz = x.second.size() - 1;
      ll sum = 2LL * x.second.front() + sz * d;
      sum *= (sz + 1);
      sum /= 2;
      ll acc = accumulate(x.second.begin(), x.second.end(), 0LL);
      // cout << acc << " " << sum << endl;
      if (sum == acc) {
        sol.push_back({x.first, d});
      }
    }
    cout << sol.size() << "\n";
    for(auto el : sol) {
      cout << el.first << " " << el.second << "\n";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
