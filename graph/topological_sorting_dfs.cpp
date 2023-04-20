#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10000 + 10;
int n, m, _in[N];
bool vis[N], tmp[N];
vector<vector<int>> G;
vector<int> topo;



void init() {
    memset(vis, 0, sizeof(vis));
    memset(_in, 0, sizeof(_in));
    memset(tmp, 0, sizeof(tmp));
    cin >> n >> m;
    G.clear();
    G.resize(n+1);
    topo.clear();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        _in[v]++;
    }
}

void dfs(int i) {
    if (!_in[i] && !vis[i] && !tmp[i]) {
        topo.emplace_back(i);
        vis[i] = true;
        tmp[i] = true;
        for (auto &j : G[i]) {
            _in[j]--;
            dfs(j);
        }
        tmp[i] = false;
    }
}

bool toposort() {
    for (int i = 1; i <= n; i++) dfs(i);
    return ((int)topo.size() == n);
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
