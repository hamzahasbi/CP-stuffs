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
   freopen("../../io/input.in", "r", stdin);
  //  freopen("io/output.out", "w", stdout);
  #endif
}

struct Cell {
    int row, col, dist;
    int directions[4] = {0}; // Up, Down, Left, Right
};
vector<vector<Cell>> dijkstraGrid;
vector<vector<int>>grid;
int n, m;
const int INF = INT_MAX;

void dijkstra(pair<int, int> source) {

    // Priority queue to store cells with the minimum distance
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Set initial distances to infinity
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dijkstraGrid[i][j].dist = INF;
        }
    }

    // Starting cell has distance 0
    dijkstraGrid[source.first][source.second].dist = 0;
    pq.push({0, source});

    // Arrays to represent possible movements: Up, Down, Left, Right
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};

    while (!pq.empty()) {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();

        int currRow = top.second.first;
        int currCol = top.second.second;
        int currDist = top.first;

        if (currDist > dijkstraGrid[currRow][currCol].dist) {
            continue;
        }

        // Explore neighboring cells
        for (int i = 0; i < 4; ++i) {
            int newRow = currRow + dx[i];
            int newCol = currCol + dy[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                // Check if the opposite direction is used
                if (dijkstraGrid[currRow][currCol].directions[i] >= 3 || (dijkstraGrid[newRow][newCol].directions[i] > 0 && dir[i] != dijkstraGrid[newRow][newCol].directions[i])) {
                    continue;
                }

                int newDist = currDist + grid[newRow][newCol];

                // Update distance if a shorter path is found
                if (newDist < dijkstraGrid[newRow][newCol].dist) {
                    dijkstraGrid[newRow][newCol].dist = newDist;
                    pq.push({newDist, {newRow, newCol}});

                    // Update the direction count for the new cell
                    dijkstraGrid[newRow][newCol].directions[i] = dir[i];
                }
            }
        }
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string s;
    int ans = 0LL;
    while(cin >> s) {
      vector<int>line;
      for(auto el : s) {
        line.push_back(el - '0');
      }
      grid.push_back(line);
      m = (int) s.size();
    }
    n = grid.size();

    pair<int, int> source = make_pair(0, 0);
    dijkstraGrid.resize(n, vector<Cell>(m));
    dijkstra(source);
    // for(int i = 0; i < n; ++i) {
    //   for(int j = 0; j < m; ++j) {
    //     cout << dijkstraGrid[i][j].dist << " ";
    //   }
    //   cout << endl;
    // }
    cout << dijkstraGrid[n - 1][m - 1].dist << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    //cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
