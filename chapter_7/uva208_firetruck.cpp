#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
using namespace std;

const int N = 21;
int k, u, v, kase, cnt, G[N][N], cur, ans[N];
bool vis[N];

// 检查是否能从结点 k 到达 1
bool check(int u) {
    if (u == 1) return true;
    vis[u] = true;
    for (int v = 1; v < N; v++)
        if (!vis[v] && G[u][v] && check(v)) return true;
    return false;
}
// 回溯法按字典序打印解
void dfs(int u, int cur) {
    ans[cur] = u;
    if (u == k) {
        cnt++;
        for (int i = 0; i <= cur; i++) {
            if (!i) cout << ans[i]; 
            else cout << ' ' << ans[i];
        }
        cout << "\n";
    } else {
        for (int v = 1; v < N; v++)
            if (!vis[v] && G[u][v]) {
                vis[v] = true;
                dfs(v, cur+1);
                vis[v] = false;
            }
    }
}

void solve() {
    cout << "CASE " << ++kase << ":\n";
    memset(vis, 0, sizeof(vis));
    if (!check(k)) cout << "There are 0 routes from the firestation to streetcorner " << k << ".\n";
    else {
        memset(vis, 0, sizeof(vis));
        vis[1] = true;
        cnt = 0;
        dfs(1, 0);
        cout << "There are " << cnt << " routes from the firestation to streetcorner " << k << ".\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("uva208.in", "r", stdin);
    freopen("uva208_.out", "w", stdout);
#endif
    IOS
    while (cin >> k && k) {
        memset(vis, 0, sizeof(vis));
        memset(G, 0, sizeof(G));
        while (cin >> u >> v && u && v) {  // 无向图
            G[u][v] = 1;
            G[v][u] = 1;
        }
        solve();
    }
    return 0;
}