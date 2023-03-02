// 使用一个支持动态增加元素的数据结构构成的数组，如 vector<int> adj[n + 1] 来存边，
// 其中 adj[u] 存储的是点 u 的所有出边的相关信息（终点、边权等）
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> vis;
vector<vector<int> > adj;

// 查找边(u,v)是否存在
bool find_edge(int u, int v) {
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) return true;
    }
    return false;
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cout << u << ' ';
    for (int i = 0; i < adj[u].size(); i++) dfs(adj[u][i]);
}

int main() {
    cin >> n >> m;

    vis.resize(n + 1, false);
    adj.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) dfs(i);
    cout << endl;

    cout << find_edge(2, 5) << endl;

    return 0;
}
