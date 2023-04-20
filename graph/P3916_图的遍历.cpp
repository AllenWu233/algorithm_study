#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, cnt, u, v, MAX;
int nxt[maxn], head[maxn], to[maxn];
int vis[maxn];


// head[u]初始值为 -1
void add(int u, int v) {
    nxt[cnt] = head[u];  // 以 u 为起点的上一条边的编号
    head[u] = cnt;       // 以 u 为起点的最后一条边的编号
    to[cnt++] = v;       // 终点
}

void dfs(int u, int w) {
    vis[u] = w;
    MAX = max(MAX, to[u]);
    cout << u << endl;
    for (int i = head[u]; ~i; i = nxt[i]) {  // ~i <==> i != -1
        if (!vis[to[i]]) dfs(to[i], w);
    }
}

int main() {
#ifdef LOCAL
    freopen("p3916.in", "r", stdin);
    // freopen("p3916_.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(head, -1, sizeof(head));  // 初始化；nxt[i] = -1表示到达终点
    // 反向存图，以便反向查找各点所能到达的编号最大的点
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        add(v, u);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << endl;
    //     for (int j = head[i]; ~j; j = nxt[j]) {
    //         cout << i << ' ' << to[j] << ' ' << endl;
    //     }
    //     cout << endl;
    // }

    // 反向DFS
    for (int i = n; i > 0; i--)
        if (!vis[i]) dfs(i, i);
    // 打印结果
    for (int i = 1; i <= n; i++) cout << vis[i] << ' ';

    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << head[i] << ' ';
    // } cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << nxt[i] << ' ';
    // } cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << to[i] << ' ';
    // } cout << endl;
    return 0;
}
