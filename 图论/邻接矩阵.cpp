// 使用一个二维数组 G 来存边，其中 G[u][v] 为 1 表示
//  存在 u 到 v 的边，为 0 表示不存在
// 如果是带边权的图，可以在 G[u][v] 中存储 u 到 v 的边的边权
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000;
int n, m;
bool vis[maxn];
int G[maxn][maxn];

// 查找边(u,v)是否存在
bool find_edge(int u, int v) { return G[u][v]; }

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    cout << u << ' ';
    for (int v = 1; v <= n; v++)
        if (G[u][v]) dfs(v);
}

int main() {
    // 一共有n个点,m条边
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = w;
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        dfs(i);
        cout << '\n';
    }
    cout << endl;

    cout << find_edge(3, 1) << endl;
    cout << find_edge(4, 5) << endl;
    return 0;
}
/*
5 6
1 2 1
2 3 2
1 3 3
3 1 10
3 4 3
5 2 7
*/