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

pair<int,int>dir(char c, int i, int j) {
  if (c == 'D') {
    return make_pair(i + 1, j );
  } else if (c == 'U') {
    return make_pair(i - 1, j );
  } else if (c == 'R') {
    return make_pair(i, j + 1);
  } else if (c == 'L') {
    return make_pair(i, j - 1 );
  }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    READ();
    int n,m,sz;
    cin >> n >> m >> sz;
    string t;
    cin >> t;
    vector<string>grid(n);
    vector<pair<int, int>>root;
    for(int i = 0; i < n; ++i) {
      cin >> grid[i];
      // debug(grid[i]);
      for(int j = 0; j < m; ++j) {
        if (grid[i][j] == '.') {
          root.push_back({i, j});
        }
      }
    }

    auto can = [&] (pair<int,int> pos) {
      return grid[pos.first][pos.second] == '.';
    };
    int ans = 0;
    for(auto start : root) {
      bool to_count = true;
      auto curr = start;
      for(auto c : t) {
        curr = dir(c, curr.first, curr.second);
        if (!can(curr)) {
          to_count = false;
          break;
        }
      }
      ans += to_count;
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
