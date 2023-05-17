#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int N = 100 + 10, M = 6000 + 20;
int n, m, dist[N][N];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dist[i][j] = i == j ? 0 : INF;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
}

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    IOS
    init();
    floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << dist[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}
