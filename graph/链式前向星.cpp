#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m, idx;
int h[N], ne[N], to[N], e[N], vis[N];


// head[u]初始值为 -1
void add_edge(int u, int v, int w) {
    to[idx] = v;     // 终点
    e[idx] = w;      // 边权
    ne[idx] = h[u];  // 以 u 为起点的上一条边的编号
    h[u] = idx++;    // 更新以 u 为起点上一条边的编号   
}

void dfs(int u) {
    cout << u << ' ';
    vis[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {  // ~i 相当于 i != -1
        if (!vis[to[i]]) dfs(to[i]);
    }
}

void print() {   // 遍历各点出边终点
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (int j = h[i]; ~j; j = ne[j])
            cout << to[j] << ' ';
        cout << "\n";
    }
}

int main() {
    memset(h, -1, sizeof(h));  // 初始化；ne[i] = -1表示到达终点
    
    // 存图
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;        
        cin >> u >> v >> w;
        add_edge(u, v, w);
        // add_edge(v, u, w);  // 无向边

        // 输出存储过程
        cout<<"to["<<idx-1<<"] = "<<to[idx-1]<<"; "
            <<"ne["<<idx-1<<"] = "<<ne[idx-1]<<"; "
            <<"h["<<u<<"] = "<<h[u]<<";\n";
    }

    print();

    int Max;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        Max = i;
        dfs(i);
        cout << Max << "\n";
    }


    // 输出存储结果
    cout << "\n";
    for (int i = 0; i <= n; i++) {
        cout << "h[" << i << "] = " << h[i] << ", ";
        cout << "ne[" << i << "] = " << ne[i] << ", ";
        cout << "to[" << i << "] = " << to[i] << ", ";
        cout << "e[" << i << "] = " << e[i] << ",\n";
    }
    return 0;
}
/*  输入示例：
4 3
1 2 5
2 4 10
4 3 15
*/