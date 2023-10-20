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
set<int>primes;

bool is_prime(int x)
{
    for(int i = 2; i < sqrt(x)+1; i++)
    if(x % i == 0) return false;
    return true;
}

void generator()
{
    primes.insert(2);
    for(int i = 3; i <= 32000; i++)
    if(is_prime(i)) primes.insert(i);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d", &t);
    generator();
    while(t--)
    {
        int n;
        scanf("%d", &n);

        vector<pair<int,int>>ans;
        map<int,bool>marked;
        for(int i = 2; i < n; i++)
        {
            if(primes.find(i)!= primes.end() && primes.find(n - i) != primes.end() && !marked[i] && !marked[n - i])
            {
                ans.push_back(make_pair(i, n - i));
                marked[i] = true;
                marked[n - i] = true;
            }
        }
        cout << n << " has " << ans.size() << " representation(s)" << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].first << "+" << ans[i].second << endl;
        }
        cout << endl;
    }


  return 0;
}
