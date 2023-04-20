#pragma GCC optimize(3)

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PII pair<int, int>
#define fi first
#define se second

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
bool vis[N];
int dist[N], s;
vector<vector<PII>> G;
int n, m;


void add(int u, int v, int w) { 
    G[u].emplace_back(make_pair(w, v));  // pair< (u,v)边权, 结点编号v >
    // G[v].emplace_back(make_pair(w, u));  // 无向图
}

void init() {
    cin >> n >> m >> s;
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    G.clear();
    G.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
}

void dijkstra(int k) {
    dist[k] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;  // 小根堆
    pq.push(make_pair(0, k));  // pair< s到v当前的最短路, 结点编号v >
    while (!pq.empty()) {
        PII tmp = pq.top();
        pq.pop();
        int u = tmp.se;
        if (vis[u]) continue;
        // 未搜索的结点才需遍历
        vis[u] = true;
        for (auto &i : G[u]) {
            int v = i.se, w = i.fi;
            // 松弛操作
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("P4779_1.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    init();
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << "\n";
    return 0;
}
