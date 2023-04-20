#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
const int INF = 2147483647;
bool vis[N];
int dist[N], s;

struct Node {
    int v, w;
    // 用于邻接表时：v为结点编号，w为(u,v)边权
    // 用于优先队列时：v为结点编号，w为当前从s到v的最短路
    // 可用pair代替
    bool operator < (const Node &a) const {
        return w > a.w;
    }
};

vector<vector<Node>> G;
int n, m;


void add(int u, int v, int w) { 
    Node t = {v, w};
    G[u].emplace_back(t);
}

void init() {
    cin >> n >> m >> s;
    G.clear();
    G.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) dist[i] = INF;
}

void dijkstra(int k) {
    dist[k] = 0;
    priority_queue<Node> pq;
    pq.push({k, 0});
    while (!pq.empty()) {
        Node tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if (vis[u]) continue;
        // 未搜索的结点才需遍历
        vis[u] = true;
        for (auto &i : G[u]) {
            int v = i.v, w = i.w;
            // 松弛操作
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
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