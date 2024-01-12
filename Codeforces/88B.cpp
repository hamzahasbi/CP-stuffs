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

map<char, int>dis;
int can(map<char, vector<pair<int,int>>> &mp, vector<string>&keys, char target, int& mx) {
  if (dis.count(target)) return dis[target];
  if (mp.count(target) && target != 'S') return 0;
  if (!mp.count('S') || (!mp.count(toupper(target)) && !mp.count(tolower(target)))) return -1;
  bool lower = target >= 'a' && target <= 'z';
  char search = lower ? toupper(target) : tolower(target);


  int d = INT_MAX;
  for(int i = 0; i < mp['S'].size(); ++i) {
    int shift_x = mp['S'][i].first;
    int shift_y = mp['S'][i].second;
    for(int j = 0; j < mp[search].size(); ++j) {
      int x = mp[search][j].first;
      int y = mp[search][j].second;
      if (x == shift_x && y == shift_y && search == 'S') continue;
      d = min(d, (int) pow(x - shift_x, 2) + (int) pow(y - shift_y, 2));
    }
  }
  // cout << d << endl;
  return dis[target] = d <= mx ? 0 : (d ==INT_MAX ? -1 : 1);
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int n,m, x;
    cin >> n >> m >> x;
    x *= x;
    vector<string>keys(n);
    map<char, vector<pair<int,int>>>mp;
    for(int i = 0; i < n; ++i) {
      cin >> keys[i];
      for(int j = 0; j < m; ++j) {
        mp[keys[i][j]].push_back({i, j});
      }
    }
    int ans = 0;
    int q;
    cin >> q;
    int last = -1;
    string target;
    cin >> target;
    for(int i = 0; i < q; ++i) {
      last = can(mp, keys, target[i], x);
      if (last == - 1) {
        cout << -1 << "\n";
        return 0;
      }
      ans += last;
    }
    cout << ans << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
