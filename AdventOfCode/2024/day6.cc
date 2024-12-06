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
   freopen("../../io/input.in", "r", stdin);
  //  freopen("../../io/output.out", "w", stdout);
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
    READ();
    vector<string>grid;
    string s;
    pair<int, int>guard;
    while(cin >> s) {
      grid.push_back(s);
      int i = grid.size() - 1;
      for(int j = 0; j < s.size(); ++j) {
        if (s[j] != '.' && s[j] != '#') {
          guard = {i, j};
          break;
        }
      }
    }
    int n = grid.size();
    int m = grid.back().size();
    auto valid = [&] (int i, int j) {
      return (i <= n - 1 && i >= 0 && j >= 0 && j <= m - 1);
    };
    auto go = [&] (int i, int j, char curr) {
      pair<int, int> next;
      if (curr == '^') {
        next = {i - 1, j};
      } else if (curr == '<') {
        next = {i, j - 1};
      } else if (curr == '>') {
        next = {i, j + 1};
      } else {
        next = {i + 1, j};
      }
      return next;
    };

    auto turn = [&] (int i, int j, char curr) {
      tuple<int, int, char> next;
      if (curr == '>') {
        next = make_tuple(i + 1, j, 'v');
      } else if (curr == '^') {
        next = make_tuple(i, j + 1, '>');
      } else if (curr == '<') {
        next = make_tuple(i - 1, j, '^');
      } else {
        next = make_tuple(i, j - 1, '<');
      }
      return next;
    };
    queue<pair<int, int>>q;
    map<tuple<int, int, char>, bool> vis;
    set<pair<int, int>>d;
    char dir = grid[guard.first][guard.second];
    q.push(guard);
    int ans = 0;
    while(!q.empty()) {
      auto v = q.front();
      q.pop();
      debug(v.first, v.second, dir);

      if (v.first == 0 || v.first == n - 1 || v.second == 0 || v.second == m - 1) {
        if (grid[v.first][v.second] == '.') break;
      }
      d.insert(v);
      // vis[make_tuple(v.first, v.second, grid[v.first][v.second])] = true;
      auto p = go(v.first, v.second, dir);
      if (valid(p.first, p.second)) {
        if (grid[p.first][p.second] == '.') {
          // grid[p.first][p.second] = grid[v.first][v.second];
          q.push(p);
        } else {
          auto u = turn(v.first, v.second, dir);
          auto [next_i, next_j, next_dir] = u;
          dir = next_dir;
          // grid[next_i][next_j] = next_dir;
          q.push({next_i, next_j});

        }
      }
      grid[v.first][v.second] = '.';
    }
    cout << d.size() + 1 << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
