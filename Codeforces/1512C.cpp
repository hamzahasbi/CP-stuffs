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
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    
    	int t;
	cin>>t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int n = s.size();
		

        a -= count(s.begin(), s.end(), '0');
        b -= count(s.begin(), s.end(), '1');
		
		for(int i = 0; i < n; i++) {
			if(s[i] == '?') {
				if(s[n - i - 1] == '0') {
					if(a) {
						a--;
						s[i] = s[n - i - 1];
					}
				} else if(s[n-i-1] == '1') {
					if(b) {
						b--;
						s[i] = s[n - i - 1];
					}
				}
			}
		}
		
		bool flag = true;
		
		for(int i = 0; i < n/2; i++) {
			if(s[i] != s[n - i - 1]) {
				flag = false;
			}
		}
		
		if((a % 2 == 1 && b % 2 ==1) || a < 0 || b < 0) flag = false;
		
		if(!flag) {
			cout<< -1 << endl;
			continue;
		}
		
		for(int i = 0; i < n/2; i++) {
			if(s[i] == '?') {
				if(a > 1) {
					s[i] = '0';
					s[n - i - 1] = '0';
					a -= 2;
				} else if(b > 1) {
					s[i] = '1';
					s[n - i - 1] = '1';
					b -= 2;
				}
			}
		}
		
		if (a) s[n / 2] = '0';
		if (b) s[n / 2] = '1';
		
		cout<< s << endl;
 		
	}
/*     auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    cout << "Finished in " << duration << " ms" << endl; */
    return 0;
}