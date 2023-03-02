#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, cnt;
int head[maxn];
int vis[maxn];

struct Node {
    int w;  // 权值
    int nxt;  // 前继
    int to;  // 终点
} edge[maxn];


// head[u]初始值为 -1
void add(int u, int v, int w) {
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];  // 以 u 为起点的上一条边的编号
    head[u] = cnt;       // 以 u 为起点的最后一条边的编号
    edge[cnt++].to = v;       // 终点
}

// void dfs(int u) {
//     for (int i = head[u]; ~i; i = nxt[i]) {  // ~i <==> i != -1
//         if (!vis[to[i]]) dfs(to[i]);
//     }
// }

void print() {
    // 遍历出边
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
        for (int j = head[i]; ~j; j = edge[j].nxt) {
            cout << i << ' ' << edge[i].to << ' ' << endl;
        }
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("p3916.in", "r", stdin);
    // freopen("p3916_.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    memset(head, -1, sizeof(head));  // 初始化；nxt[i] = -1表示到达终点
    
    // 存图
    for (int i = 1; i <= m; i++) {
        memset(head, -1, sizeof(head));
        int u, v, w;        
        cin >> u >> v >> w;
        add(u, v, w);
        // 输出过程
        cout<<"to["<<cnt-1<<"] = "<<edge[cnt-1].to<<"; "
            <<"nxt["<<cnt-1<<"] = "<<edge[cnt-1].nxt<<"; "
            <<"head["<<u<<"] = "<<head[u]<<";\n";
    }

    // for (int i = n; i > 0; i--)
    //     if (!vis[i]) dfs(i, i);

    // 输出存储结果
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << "head[" << i << "] = " << head[i] << ", ";
        cout << "edge[" << i << "].nxt = " << edge[i].nxt << ", ";
        cout << "edge[" << i << "].to = " << edge[i].to << ", ";
        cout << "edge[" << i << "].w = " << edge[i].w << ",\n";
    }
    return 0;
}
