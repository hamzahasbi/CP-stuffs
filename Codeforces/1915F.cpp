/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

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
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template <class T> struct FenwickTree {
    vector<T> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0LL);
    }

    // O(n * log(n)) Linear construction
    FenwickTree(vector<T> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    T sum(int r) {
        T ret = 0LL;
        for (; r > 0; r -= r & (-r))
            ret += bit[r];
        return ret;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, ll delta) {
        for (; idx < n; idx += idx & (-idx))
            bit[idx] += delta;
    }
    // O(n) Linear construction
  //   build(vector<int> const &a) : FenwickTree(a.size()){
  //   for (int i = 0; i < n; i++) {
  //       bit[i] += a[i];
  //       int r = i | (i + 1);
  //       if (r < n) bit[r] += bit[i];
  //   }
  // }
};

ll solve(vector<pair<ll,ll>> a) {
  ll ans = 0;
  ordered_set.clear();
  for(int i = 0; i < a.size(); ++i) {
    ans += ordered_set.order_of_key(a[i].first);
    ordered_set.insert(a[i].first);
  }
  return ans;
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

      vector<pair<ll,ll>> a(n);
      vector<ll>compress;
      for (int i = 0; i < n; ++i) {
          cin >> a[i].first >> a[i].second;
          compress.push_back(a[i].first);
          compress.push_back(a[i].second);
      }
      sort(a.begin(), a.end(), [&] (pair<ll, ll>x, pair<ll, ll> y) {
        return x.second < y.second;
      });
      cout << solve(a) << endl;
      continue;
      sort(compress.begin(), compress.end());
      // Transform into indexes to find inversions using BIT.
      FenwickTree<ll> BIT (2 * n + 1);
      ll ans = 0;
      for(int i = 0; i < n ; ++i) {
        int from = lower_bound(compress.begin(), compress.end(), a[i].first) - compress.begin() + 1;
        int to = lower_bound(compress.begin(), compress.end(), a[i].second) - compress.begin() + 1;

        ans += BIT.sum(from, to);
        BIT.add(to, 1LL);
      }
      cout << ans << endl;

    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
