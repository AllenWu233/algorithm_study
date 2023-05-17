#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _all(x) (x).begin(), (x).end()

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n, m;
vector<int> G[N];
bool vis[N];


void init() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++) sort(_all(G[i]));
}

void dfs(int k, int cur) {
    if (cur == n || vis[k]) return; 
    vis[k] = true;
    cout << k << ' ';
    for (auto &i : G[k]) {
        if (!vis[i]) dfs(i, cur+1);
    }
}

void bfs() {
    queue<int> q; 
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << ' ';
        for (auto &i : G[t]) {
            if (!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    IOS
    init();
    dfs(1, 0);
    cout << "\n";
    memset(vis, 0, sizeof(vis));
    bfs();
    cout << "\n";
    return 0;
}
