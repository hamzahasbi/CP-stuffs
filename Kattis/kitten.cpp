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
vector<string> split(string& str, char delim = ' ')
{
    stringstream ss(str);
    string token;
    vector<string> cont;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
    return cont;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    READ();
    int k;
    cin >> k;
    string line;
    unordered_map<int, vector<int>>tree;
    map<int, bool>isNotRoot;
    int root = -1;
    while(getline(cin, line)) {
        if (line == "-1") break;
        vector<int> extracted;
        for(auto &el : split(line)) {
            extracted.push_back(stoi(el));
        }
        for(int i = 1; i < extracted.size(); ++i) {
            isNotRoot[extracted[i]] = true;
            tree[extracted[0]].push_back(extracted[i]);
            tree[extracted[i]].push_back(extracted[0]);
        }
    }
    for(auto p : tree) {
        if (!isNotRoot.count(p.first)) {
            root = p.first;
            break;
        }
    }
    queue<int> bfs;
    map<int, pair<int, int>>path;
    bfs.push(k);
    path[k] = {0, -1};

    while(!bfs.empty()) {
        auto node = bfs.front();
        bfs.pop();
        for(auto v : tree[node]) {
            if (!path.count(v)) {
                bfs.push(v);
                path[v].first = path[node].first + 1;
                path[v].second = node;
            }
        }
    }

    vector<int>ans;
    ans.push_back(root);
    while(root != -1) {
        ans.push_back(path[root].second);
        root = path[root].second;
        if (root == k) break;
    }
    reverse(ans.begin(), ans.end());
    for(auto &v : ans) cout << v << " ";
    cout << endl;
    // auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - start ).count();
    // cout << "Finished in " << duration << " ms" << endl;
    return 0;
}