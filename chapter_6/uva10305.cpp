// 拓扑排序
// n个点，m条边
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int G[maxn][maxn];  // 邻接矩阵
int vis[maxn];
int topo[maxn];  // 拓扑序
int t, m, n;


bool dfs(int u) {
    vis[u] = -1;
    for (int v = 1; v <= n; v++) {
        if (G[u][v]) {
            if (vis[v] < 0) return false;
            else if (!vis[v] && !dfs(v)) return false;
        }
    }
    vis[u] = 1;
    topo[--t] = u;
    return true; 
}

bool toposort() {
    t = n;
    memset(vis, 0, sizeof(vis));
    for (int u = 1; u <= n; u++) {
        if (!vis[u] && !dfs(u)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("uva10305.in", "r", stdin);
    // freopen("uva10305_.out", "w", stdout);
#endif
    IOS
    while (cin >> n >> m && n) {  // 注意m可能等于0
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            G[u][v] = 1;
        }
        if (toposort()) {
            for (int i = 0; i < n; i++) {
                if (i) cout << ' ';
                cout << topo[i];
            }
            cout << '\n';
        } else cout << "No\n";
    }
    return 0;
}