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
  //  freopen("../../io/output.out", "w", stdout);
  #endif
}

void transform(string s, map<char, int>&f) {
  int mx = 0;
  char mxC;
  vector<char>possible;
  for(auto el : f) {
    if (el.first != 'J') {
      if (el.second > mx) {
        mx = el.second;
        mxC = el.first;
      }
    }
  }

  f[mxC] += f['J'];
  f.erase('J');
}

int handType(string s) {
  map<char, int>f;

  for(auto c : s) {
    f[c]++;
  }
  // part 2
  transform(s, f);
  if (f.size() == 5) return 1;
  if (f.size() == 1) return 7;
  if (f.size() == 2) {
    for(auto el : f) {
      if (el.second == 4) {
        return 6;
      }
    }
    return 5;
  }
  if (f.size() == 3) {
    for(auto el : f) {
      if (el.second == 3) {
        return 4;
      }
    }
    return 3;
  }
  return 2;
}

int cardValue(char c) {
  unordered_map<char, int>conv;
  int ans = 1;
  conv['2'] = ans++;
  conv['3'] = ans++;
  conv['4'] = ans++;
  conv['5'] = ans++;
  conv['6'] = ans++;
  conv['7'] = ans++;
  conv['8'] = ans++;
  conv['9'] = ans++;
  conv['T'] = ans++;
  conv['J'] = ans++;
  conv['Q'] = ans++;
  conv['K'] = ans++;
  conv['A'] = ans++;
  // part 2
  conv['J'] = -1;
  return conv[c];
}

bool compare(pair<string, int> a, pair<string, int> b) {
  if (handType(a.first) > handType(b.first)) return true;
  if (handType(a.first) == handType(b.first)) {
    for(int i = 0; i < a.first.size(); ++i) {
      bool diff = a.first[i] != b.first[i];
      if (diff) return (cardValue(a.first[i]) > cardValue(b.first[i]));
    }
    return false;
  }
  return false;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string s;
    int bet;
    vector<pair<string, int>>rounds;
    long long ans = 0LL;

    while(cin >> s >> bet) {
      rounds.push_back({s, bet});
    }
    sort(rounds.rbegin(), rounds.rend(), compare);
    int len = rounds.size();
    for(int i = 0; i < rounds.size(); ++i) {
      // cout << rounds[i].first << endl;
      ans += (i + 1) * rounds[i].second;
    }
    cout << ans << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
