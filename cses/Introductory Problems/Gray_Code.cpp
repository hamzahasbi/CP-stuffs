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
vector<string> sol;
int n;
char flip(char c) {
  return (c == '0') ? '1' : '0';
}

int diff (string s, string p) {
  int a = 0;
  for(int i = 0; i < s.size(); ++i) {
    a = s[i] != p[i];
  }
  return a;
}

// void solve(string s, int i) {
//   if (i == n) return;
//   sol[s] = true;
//   // cout << s << " " << i << endl;
//   string l , r;
//   l = s;
//   r = s;
//   l[i] = '0';
//   r[i] = '1';

//   solve(l, i + 1);
//   solve(r, i + 1);
// // ;handle identify __Morty
// }
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();

    cin >> n;
    string s = "";
    string ss = "";
    s.assign(n, '0');
    ss.assign(n, '1');
    stack<pair<string, int>>q;
    map<string, bool> mp;
    q.push({s, 0});
    while(!q.empty()) {
      auto l = q.top();
      q.pop();
      if (mp.count(l.first)) continue;
      mp[l.first] = true;
      sol.push_back(l.first);
      for(int i = 0; i < n; ++i) {
        string ss = l.first;
        ss[i] = flip(l.first[i]);
        if (!mp.count(ss)) {
          q.push({ss, i});
        }

      }
    }

    for(auto el : sol) {
      cout << el << endl;
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
