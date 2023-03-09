// 使用一个支持动态增加元素的数据结构构成的数组，如 vector<int> G[n + 1] 来存边，
// 其中 G[u] 存储的是点 u 的所有出边的相关信息（终点、边权等）
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int v;  // 边的终点
    int w;  // 边权
};

int n, m;
vector<int> vis;
vector<vector<Node> > G;  // 存储点 u 的所有出边的相关信息（终点、边权等）

// 查找边(u,v)是否存在
bool find_edge(int u, int v) {
    for (int i = 0; i < (int)G[u].size(); i++)
        if (G[u][i].v == v) return true;
    return false;
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cout << u << ' ';
    for (int i = 0; i < (int)G[u].size(); i++) dfs(G[u][i].v);
}

int main() {
    // 一共有n个点,m条边
    cin >> n >> m;

    vis.resize(n+1, false);
    G.resize(n+1);

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        dfs(i);
        cout << endl;
    }

    cout << find_edge(1, 2) << endl;

    return 0;
}
