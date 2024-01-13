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

int n,m,k,t;
// Brute force.
void puzzle(vector<string>&grid, map<pair<int,int>, bool>&waste) {
  string init = "";
  init.assign("*", m);
  grid.resize(n, init);
  int type = 0;
  for(int i = 0; i < n; ++i) {
    string line = "";
    for(int j = 0; j < m; ++j) {
      if (waste.count({i, j})) {
        grid[i][j] = '$';
      } else {
        grid[i][j] = char(type + 'a');
        type++;
        type %= 3;
      }
    }
  }
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    cin >> n >> m >> k >> t;
    ordered_set<pair<int,int>>waste;
    map<pair<int,int>,bool>w;
    vector<string>grid;
    for(int i = 0; i < k; ++i) {
      int x,y;
      cin >> x >> y;
      x--; y--;
      waste.insert({x, y});
      w[{x, y}] = true;
    }
    // puzzle(grid, w);
    while(t--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      if (w.count({x, y})) puts("Waste");
      else {
        int off = waste.order_of_key({x, y});
        auto target = x * m + y - off;
        puts(target % 3 == 0 ? "Carrots" : (target % 3 == 1 ? "Kiwis" : "Grapes"));
      }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
