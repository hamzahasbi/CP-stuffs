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
   freopen("../io/input.in", "r", stdin);
   freopen("../io/output.out", "w", stdout);
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
    vector<long long>ans;
    map<string, int>colors;
    colors["red"] = 12;
    colors["green"] = 13;
    colors["blue"] = 14;
    // for the second star we need to compute the max for each cube in each row
    while(getline(cin, s)) {
      auto line = split(s, ':');
      colors.clear();
      // this was used to get the first star.
      bool can = true;
      int id = stoi(split(line[0], ' ')[1]);
      vector<string>rounds = split(line[1], ';');
      for(auto r : rounds) {
        auto cubes = split(r, ',');
        for(auto cube : cubes) {
          auto cc = split(cube, ' ');
          int counter = stoi(cc[1]);
          string color = cc[2];
          colors[color] = max(counter, colors[color]);
        }
      }
      long long power = 1LL;
      for(auto row: colors) {
        power *= row.second * 1LL;
      }
      ans.push_back(power);
    }
    long long ff = accumulate(ans.begin(), ans.end(), 0LL);
    cout << ff << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
