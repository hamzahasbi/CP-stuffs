/*
 Author: Hamza Hasbi
 @Copyrights: __Morty
*/
#include<bits/stdc++.h>
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
//inline long long lcm(ll a,ll b) {return a * b / __gcd(a,b);}
//inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("../../io/input.in", "r", stdin);
   freopen("../../io/output.out", "w", stdout);
  #endif
}


vector<string>split(string s, char separator) {
  vector<string>ret;
  for(int i = 0; i < s.size(); ++i) {
    string temp = "";
    while(i < s.size() && s[i] != separator) {
      temp += s[i];
      ++i;
    }
    ret.push_back(temp);
  }
  return ret;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string s;
    unordered_map<long long, long long>seeds, g;
    unordered_map<long long, bool>step;
    string link = "";
    int idx = 0;
    while(getline(cin, s)) {
      if (s.empty()) continue;
      // cout << s << endl;
      if (idx == 0) {
        auto ss = split(s, ':');
        auto seed = split(ss[1], ' ');
        for(auto el : seed) {
          if (!el.empty()) {
            seeds[stoll(el)]= stoll(el);
          }
        }
        idx++;
        continue;
      }
      if (s.find("map") != string::npos) {
        idx++;
        link = s;
        step.clear();
      }
      else {
        auto ranges = split(s, ' ');
        long long target, source, offset;
        target = stoll(ranges[0]);
        source = stoll(ranges[1]);
        offset = stoll(ranges[2]);
        offset--;
        for(auto x : seeds) {
          if (x.second >= source && x.second <= source + offset && !step[x.first]) {
            long long curr = x.second - source;
            seeds[x.first] = target + curr;
            step[x.first] = true;
          }
        }
      }

    }
    long long ans = LLONG_MAX;
    for(auto x : seeds) {
      ans = min(ans, x.second);
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
