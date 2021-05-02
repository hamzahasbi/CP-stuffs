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
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string>grid(n);
        vector<pair<int, int>>point;
        for(int i = 0; i < n; ++i) {
            cin >> grid[i];
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '*') {
                    point.push_back({i, j});
                }
            }
        }

        int distanceX = abs(point[0].first - point[1].first);
        int distanceY = abs(point[0].second - point[1].second);
        point.push_back({0, 0});
        point.push_back({0, 0});
        if (distanceX) {
            point[2].first = point[0].first;
            point[3].first = point[1].first;
        } else {
            point[2].first = (point[0].first + 1) % n;
            point[3].first = (point[1].first + 1) % n;
        }

        if (distanceY) {
            point[2].second = point[1].second;
            point[3].second = point[0].second;
        } else {
            point[2].second = (point[1].second + 1) % n;
            point[3].second = (point[0].second + 1) % n;
           
        }

        for(int i = 0; i < 4; ++i) {
            grid[point[i].first][point[i].second] = '*';
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
        // cout << "_______test_____" << endl;

    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}