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

const int neighbors[][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                            {1,  -1}, {1, 0}, {1, 1},
                            {0,  -1}, {0, 1}};

int part1(const vector<string> &engine){
    int sum = 0;
    for (size_t row = 0; row < engine.size(); row++){
        int numStart = -1;
        bool found = false;

        for (size_t col = 0; col < engine[row].size(); col++){
            if (isdigit(engine[row][col])){
                if (numStart == -1){
                    numStart = col;
                }
                if (!found){
                    for (auto neigh: neighbors){
                        int y = row + neigh[0];
                        int x = col + neigh[1];

                        if (x < 0 || x >= engine[row].size() || y < 0 || y >= engine.size()){
                            continue;
                        }

                        if (engine[y][x] != '.' && !isdigit(engine[y][x])){
                            found = true;
                            // cout << engine[y][x] << endl;
                            break;
                        }
                    }
                }
            } else if (numStart != -1){
                if (found){
                	//cout << stoi(engine[row].substr(numStart, col - numStart)) << endl;
                    sum += stoi(engine[row].substr(numStart, col - numStart));
                }

                found = false;
                numStart = -1;
            }
        }

        if (numStart != -1){
            if (found){
            	//cout << stoi(engine[row].substr(numStart)) << endl;
                sum += stoi(engine[row].substr(numStart));
            }
        }
    }
    return sum;
}

int part2(const vector<string> &engine){
    int sum = 0;

    for (size_t row = 0; row < engine.size(); row++){
        for (size_t col = 0; col < engine[row].size(); col++){
            if (engine[row][col] != '*'){
                continue;
            }

            vector<int> numbers;
            vector<tuple<size_t, size_t>> numberPos;

            for (auto neigh: neighbors){
                int y = row + neigh[0];
                int x = col + neigh[1];

                if (x < 0 || x >= engine[row].size() || y < 0 || y >= engine.size()){
                    continue;
                }

                if (isdigit(engine[y][x])){
                    while (x >= 0 && isdigit(engine[y][x])){
                        x--;
                    }
                    if (x < 0 || !isdigit(engine[y][x])) {
                        x++;
                    }

                    tuple<size_t, size_t> pos(y, x);

                    if (find(numberPos.begin(), numberPos.end(), pos) == numberPos.end()){
                        numberPos.emplace_back(pos);

                        size_t start = x;
                        while (x < engine[y].size() && isdigit(engine[y][x])){
                            x++;
                        }
                        if (x == engine[y].size() || !isdigit(engine[y][x])) {
                            x--;
                        }

                        numbers.emplace_back(stoi(engine[y].substr(start, x - start + 1)));
                    }
                }
            }

            if (numbers.size() == 2){
                sum += numbers[0] * numbers[1];
            }
        }
    }

    return sum;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    READ();
    string line;

    vector<string> engine;
    while (getline(cin, line)){
        engine.push_back(line);
    }

    cout << "Part 1: " << part1(engine) << endl;
    cout << "Part 2: " << part2(engine) << endl;
    return 0;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    cout << "Finished in " << duration << " ms" << endl;
    return 0;
}
