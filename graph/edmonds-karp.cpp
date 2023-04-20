// 求解最大流问题的增广路算法
#define IOS ios::sync_with_stdin(false);cin.tie(0);cout.tie(0);

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
int n, m;
vector<Edge> edges;
vector<vector<int>> G;
int a[N], p[N];

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};


void add_edge(int from, int to, int cap) {
    edges.emplace_back(Edge(from, to, cap, 0));
    edges.emplace_back(Edge(to, from, 0, 0));  // 反向弧
    m = edges.size();
    G[from].emplace_back(m-2);
    G[to].emplace_back(m-1);
}

void init() {
    cin >> n >> m;
    edges.clear();
    G.clear();
    G.resize(n+1);
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    for (int i = 0; i < m; i++) {
        int from, to, cap;
        cin >> from >> to >> cap;
        add_edge(from, to, cap);
    }
}
