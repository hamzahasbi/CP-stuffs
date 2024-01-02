/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
#ifdef ONLINE_JUDGE
 #pragma GCC optimize("O3")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 #pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
#endif
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ud unsigned double
#define uf unsigned float
#define pi 2 * acos(0.0)
#define module cin.ignore()
template <class T> void print_v(vector<T> &v) { cout << '{'; for (auto x : v) cout << x << ','; cout << '}'; cout << endl; }
inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline long long lcm(ll a,ll b) {return a * b / gcd(a,b);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
template <class T> struct FenwickTree {
    vector<T> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    // O(n * log(n))  construction
    // FenwickTree(vector<T> const &a) : FenwickTree(a.size()) {
    //     for (size_t i = 0; i < a.size(); i++)
    //         add(i, a[i]);
    // }

    T sum(int r) {
        T ret = 0;
        for (; r > 0; r -= (r & (-r)))
            ret += bit[r];
        return ret;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, T delta) {
        for (; idx < n; idx += (idx & (-idx)))
            bit[idx] += delta;
    }
    // O(n) Linear construction
  //   build(vector<T> const &a) : FenwickTree(a.size()){
  //   for (int i = 0; i < n; i++) {
  //       bit[i] += a[i];
  //       int r = i | (i + 1);
  //       if (r < n) bit[r] += bit[i];
  //   }
  // }
};
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n, q;
    cin >> n >> q;

    FenwickTree<ll>BIT(n + 1);
    while(q--) {
      char t;
      cin >> t;
      if (t == '+' ) {
        int i;
        ll l;
        cin >> i >> l;
        // cout << i << " " << l << endl;
        BIT.add(i + 1, l);
      }
      else {
        int to;
        cin >> to;
        if (to == 0)
				  cout << "0\n";
        else cout << BIT.sum(to) << "\n";
      }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
