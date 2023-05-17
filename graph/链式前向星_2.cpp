#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int n, m, cnt;
int head[maxn];
int vis[maxn];

struct Node {
    int w;     // 边权
    int nxt;   // 前继
    int to;    // 终点
} edge[maxn];  // 边集


// head[u]初始值为 -1
void add_edge(int u, int v, int w) {
    edge[cnt].to = v;         // 终点
    edge[cnt].w = w;          // 边权
    edge[cnt].nxt = head[u];  // 以 u 为起点的上一条边的编号
    head[u] = cnt++;          // 更新以 u 为起点上一条边的编号
}

void dfs(int u) {
    cout << u << ' ';
    for (int i = head[u]; ~i; i = edge[i].nxt) {  // ~i <==> i != -1
        int to = edge[i].to;
        if (!vis[to]) dfs(to);
    }
}

void print() {   // 遍历出边
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = head[i]; ~j; j = edge[j].nxt)
            cout << edge[j].to << ' ';
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("p3916.in", "r", stdin);
    // freopen("p3916_.out", "w", stdout);
#endif
    memset(head, -1, sizeof(head));  // 初始化；nxt[i] = -1表示到达终点
    
    // 存图
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;        
        cin >> u >> v >> w;
        add_edge(u, v, w);

        // 输出存储过程
        cout<<"to["<<cnt-1<<"] = "<<edge[cnt-1].to<<"; "
            <<"nxt["<<cnt-1<<"] = "<<edge[cnt-1].nxt<<"; "
            <<"head["<<u<<"] = "<<head[u]<<";\n";
    }

    print();

    int Max;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        Max = i;
        dfs(i);
        cout << Max << endl;
    }


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
/*  输入示例：
4 3
1 2 5
2 4 10
4 3 15
*/