#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 25;
struct Node { int nxt; int to; } edge[maxn];
int k, cnt, kase;
int head[maxn];
bool vis[maxn];

void add_edge(int u, int v) {
    edge[cnt].nxt = head[u];  // 以 u 为起点的上一条边的编号
    head[u] = cnt;       // 以 u 为起点的最后一条边的编号
    edge[cnt++].to = v;       // 终点
}

bool dfs(int u) {
    if (u == k) return true;
    cout << u << endl;
    vis[u] = true;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int to = edge[i].to;
        if (!vis[to]) dfs(to);
    }
    return false;
}

void bfs() {
    queue<vector<int>> q;
    vis[1] = true;
    vector<int> tmp;
    tmp.push_back(1);
    q.push(tmp);
    while (!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        if (t.back() == k) {
            for (auto i : t) cout << i << ' ';
            cout << '\n';
            continue;
        }
        for (int i = head[t.back()]; ~i; i = edge[i].nxt) {
            int to = edge[i].to;
            if (!vis[to]) {
                t.push_back(to);
                q.push(t);
                vis[to] = true;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("uva225.in", "r", stdin);
    freopen("uva225_.out", "w", stdout);
#endif
    while (cin >> k && k) {
        memset(head, -1, sizeof(head));
        int u, v, ans = 0;
        while ((cin >> u >> v) && u && v) {
            add_edge(u, v);
            add_edge(v, u);
        }
        memset(vis, false, sizeof(vis));
        if (dfs(1)) {
            cout << "yes\n";
            memset(vis, false, sizeof(vis));
            bfs();
        } else ans = 0;
        cout<<"CASE "<<++kase<<":\n"
            <<"There are "<<ans<<" routes from the firestation to streetcorner "
            <<k<<".\n";
    }
    return 0;
}