#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10000 + 10;
int n, m, _in[N];
bool vis[N];
vector<vector<int>> G;
vector<int> topo;



void init() {
    memset(vis, 0, sizeof(vis));
    memset(_in, 0, sizeof(_in));
    cin >> n >> m;
    G.clear();
    G.resize(n+1);
    topo.clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        _in[v]++;
    }
}

bool toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!_in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.emplace_back(u);
        for (auto &v : G[u]) {
            _in[v]--;
            if (!_in[v]) q.push(v);
        }
    }
    return (int)topo.size() == n;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        if (toposort()) {
            for (auto &i : topo) cout << i << ' ';
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}

