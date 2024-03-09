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
    vector<ll>a(n);
    map<ll,pair<ll, ll>>g;
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for(int i = 2; i < n; ++i) {
      g[a[i - 1]] = make_pair(a[i - 2], a[i]);
    }
    g[a[n - 1]] = make_pair(a[n - 2], -1);
    g[a[0]] = make_pair(-1, a[1]);
    map<ll, ll>skip;
    int q;
    cin >> q;
    while(q--) {
      int type;
      cin >> type;
      if (type == 1) {
        ll x, y;
        cin >> x >> y;
        auto before = g[x];
        g[x] = make_pair(before.first, y);
        g[before.second].first = y;
        g[y] = make_pair(x, before.second);
      } else {
        ll x;
        cin >> x;
        auto before = g[x];
        ll l = before.first;
        ll r = before.second;
        g[l].second = r;
        g[r].first = l;
        g.erase(x);
      }
    }
    map<ll, ll>p;
    vector<ll>ans;
    ll root;
    for(auto el : g) {
      auto v = el.second;
      auto u = el.first;
      if (v.second == -1) root = v.second;
      p[u] = v.first;
      p[v.second] = u;
    }

    // for(auto el : p) {
    //   debug(el.first, el.second);
    // }
    map<ll, bool>vis;
    while(p.count(root)) {
      int node = p[root];
      if (node == -1) break;
      ans.push_back(node);
      root = node;
    }
    reverse(ans.begin(), ans.end());
    printVector(ans);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
