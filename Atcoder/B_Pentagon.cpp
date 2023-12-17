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
inline long long gcd(ll a,ll b) {return 1LL * b == 0 ? a : gcd(1LL*b, a * 1LL % b * 1LL);}
inline long long lcm(ll a,ll b) {return a * b / gcd(a,b);}
inline bool IsPowerOfTwo (ull x){ return (x != 0) && ((x & (x - 1)) == 0);}
using namespace std;
void READ() {
 #ifndef ONLINE_JUDGE
   freopen("io/input.in", "r", stdin);
   freopen("io/output.out", "w", stdout);
  #endif
}
bool equal(string a, string b) {
  bool f = a == b;
  f |= (a == "AB" && b == "AE");
  f |= (a == "AB" && b == "BC");
  f |= (a == "AB" && b == "CD");
  f |= (a == "AB" && b == "DE");

  f |= (a == "BC" && b == "CD");
  f |= (a == "BC" && b == "DE");
  f |= (a == "CD" && b == "DE");
  f |= (a == "AE" && b == "BC");
  f |= (a == "AE" && b == "CD");
  f |= (a == "AE" && b == "DE");

  f |= (a == "AC" && b == "CE");
  f |= (a == "AC" && b == "BD");
  f |= (a == "AC" && b == "BE");
  f |= (a == "AC" && b == "AD");

  f |= (a == "AD" && b == "CE");
  f |= (a == "AD" && b == "BE");
  f |= (a == "AD" && b == "BD");

  f |= (a == "BE" && b == "CE");
  f |= (a == "BD" && b == "BE");
  f |= (a == "BD" && b == "CE");
  return f;
}
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    char a[4];
    string l = "", r = "";

    cin >> l >> r;

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    // cout << l << " " << r << endl;
    string x, y;
    x = min(l, r);
    y = max(l, r);
    // cout << x << " " << y << endl;
    puts(equal(x, y) ? "Yes": "No");
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
