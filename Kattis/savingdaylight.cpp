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
vector<string> split(string s, char delimiter) {
  vector<string>ans;
  for(int i = 0; i < s.size(); ++i) {
    string temp = "";
    while(s[i] != delimiter && i < s.size()) {
      temp += s[i];
      ++i;
    }
    ans.push_back(temp);
  }
  return ans;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    string s;
    while(getline(cin, s)) {
      vector<string>input = split(s, ' ');

      auto from = split(input[3], ':');
      auto to = split(input[4], ':');
      int hours, minutes;
      int diff = stoi(to[0]) * 60 + stoi(to[1]) - (stoi(from[0]) * 60 + stoi(from[1]));
      hours = diff / 60;
      minutes = diff % 60;


      cout << input[0] << " " << input[1] << " " << input[2] << " " << hours << " hours " << minutes << " minutes" << endl;
    }

    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
