#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PII pair<int, int>
#define fi first
#define se second

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 2e5 + 20;
int n, m, s, idx, h[N], ne[M], to[M], e[M], dist[N];
bool vis[N];

void add(int u, int v, int w) {
    to[idx] = v, e[idx] = w, ne[idx] = h[u], h[u] = idx++; 
}

void init() {
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    cin >> n >> m >> s;
    dist[s] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
}

void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    while (!heap.empty()) {
        PII t = heap.top();
        heap.pop();
        int v = t.se, dis = t.fi;
        if (vis[v]) continue;
        vis[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = to[i];
            if (dis + e[i] < dist[j]) {
                dist[j] = dis + e[i];
                heap.push({dist[j], j});
            }
        }
    }
}


int main() {
    IOS
    init();
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    cout << "\n";
    return 0;
}
