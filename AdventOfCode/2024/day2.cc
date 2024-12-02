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
    string s;
    auto can = [&](int x) {
      return abs(x) >= 1 && abs(x) <= 3;
    };
    int ans = 0;

    while(getline(cin, s)) {
      vector<int> a;
      stringstream ss(s);
      string num;
      while(ss >> num) {
        a.push_back(stoi(num));
      }
      // Part 1.
      /* int r = *max_element(a.begin(), a.end());
      bool go = true;
      // cout << "LINE_____\n";
      for(int i = 0; i < a.size() - 1; i++) {
        int curr = a[0] == r ? a[i] - a[i + 1] : a[i + 1] - a[i];
        // debug(curr);
        go &= (curr > 0 && can(curr));
      }
      ans += go; */

      // Part 2.
      int r = *max_element(a.begin(), a.end());
      vector<int> er;
      bool go = true;
      // cout << "LINE_____\n";
      for(int i = 0; i < a.size() - 1; i++) {
        int curr = a[0] == r ? a[i] - a[i + 1] : a[i + 1] - a[i];
        // debug(curr);
        go &= (curr > 0 && can(curr));
      }
      if (!go) {
        for(int j = 0; j < a.size(); j++) {
          er = a;
          go = true;
          er.erase(er.begin() + j);
          r = *max_element(er.begin(), er.end());
          // cout << "OPERATION_____\n";
          // printVector(er);
          for(int i = 0; i < er.size() - 1; i++) {
            int curr = er[0] == r ? er[i] - er[i + 1] : er[i + 1] - er[i];
            go &= (curr > 0 && can(curr));
          }
          if (go) break;
        }
      }
      ans += go;
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
