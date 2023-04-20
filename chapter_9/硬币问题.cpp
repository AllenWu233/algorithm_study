// DAG模型
// 有 n 种硬币，面值分别为 V1, V2, ... ,Vn，每种都有无限多。
// 给定非负整数 S，可以选用多少个硬币，使得面值之和恰好为 S？输出硬币数目的最小值和最大值
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
const int INF = 0x3f3f3f3f;
using namespace std;

const int maxn = 100 + 5;
const int maxs = 10000 + 10;
int dmin[maxs], dmax[maxs];  // d[i] 表示从结点 i 出发到结点 0 的最长路长度
int n, S, V[maxn], vis[maxs];

// 记忆化搜索，要写两个
int dp_max(int S) {
    int &ans = dmax[S];
    if (vis[S]) return ans;
    vis[S] = 1;
    ans = -INF;
    for (int i = 1; i <= n; i++)
        if (S >= V[i]) ans = max(ans, dp_max(S-V[i])+1);
    return ans;
}

int dp_min(int S) {
    int &ans = dmin[S];
    if (vis[S]) return ans;
    vis[S] = 1;
    ans = INF;
    for (int i = 1; i <= n; i++)
        if (S >= V[i]) ans = min(ans, dp_min(S-V[i])+1);
    return ans;
}

void print_ans(int *d, int S) {
    // if (d[S] == INF || d[S] == -INF) {
    //     cout << "No solution.\n";
    //     return;
    // }
    for (int i = 1; i <= n; i++)
        if (S >= V[i] && d[S] == d[S-V[i]] + 1) {
            cout << V[i] << ' ';
            print_ans(d, S-V[i]);
            break;
        }
}

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> V[i];
    cin >> S;
}

int main() {
#ifdef LOCAL
    freopen("coins.in", "r", stdin);
    freopen("coins_1.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        init();
        // memset(vis, 0, sizeof(vis));
        // dp_min(S);
        memset(vis, 0, sizeof(vis));
        dp_max(S);
        // print_ans(dmin, S);
        // cout << endl;
        print_ans(dmax, S);
        cout << endl;
    }
    return 0;
}