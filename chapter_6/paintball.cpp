#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

const int maxn = 1000 + 10;
int n;
double L, R;  // 入口和出口
double x[maxn], y[maxn], r[maxn];
bool vis[maxn];

void read_input() {
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> r[i];
}

bool connect(int u, int v) {
    // 检查两圆是否相交
    return sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v])) <= (r[u] + r[v]);
}

void check_bound(int u) {
    // 检查是否与左右边界相交，更新入口和出口
    if (x[u] - r[u] < 0) 
        L = min(L, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
    if (x[u] + r[u] > 1000.0)
        R = min(R, y[u] - sqrt(r[u] * r[u] - (1000.0 - x[u])*(1000.0 - x[u])));
}

bool dfs(int u) {
    // 判断圆是否连同
    if (vis[u]) return false;
    vis[u] = true;
    if (y[u] - r[u] < 0) return true;  // 走到底
    for (int i = 0; i < n; i++) {
        if (!vis[i] && connect(u, i) && dfs(i))
            return true;
    }
    check_bound(u);
    return false;
}

void print_output() {
    for (int i = 0; i < n; i++) {
        if (y[i] + r[i] >= 1000.0 && dfs(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "0.00 " << fixed << setprecision(2) << L;  // 保留两位小数
    cout << " 1000.00 " << fixed << setprecision(2) << R << endl;
}

int main() {
#ifdef LOCAL
    freopen("paintball.in", "r", stdin);
    freopen("paintball.out", "w", stdout);
#endif
    IOS
    while (cin >> n && n) {
        L = R = 1000.0;
        memset(vis, 0, sizeof(vis));
        read_input();
        print_output();
    }
    return 0;
}