#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e5 + 50;
int idx, n, m, h[N], ne[N], to[N], _in[N];


void add(int u, int v) {
    to[idx] = v, ne[idx] = h[u], h[u] = idx++;
}

void init() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v); 
        _in[v]++;
    }
}

