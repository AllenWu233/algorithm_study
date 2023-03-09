// DAG模型
// 有 n 种硬币，面值分别为 V1, V2, ... ,Vn，每种都有无限多。
// 给定非负整数 S，可以选用多少个硬币，使得面值之和恰好为 S？输出硬币数目的最小值和最大值
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100 + 5;
const int maxV = 10000 + 10;
int d[N];  // d[i] 表示从结点 i 出发到结点 0 的最长路长度
int n, S, V[N], vis[maxV];

// 读入数据并建图
void read_input() {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) cin >> input[i][j];
        sort(&input[i][1], &input[i][1] + n);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            bool flag = true;
            for (int l = 1; l <= n; l++) {
                if (input[i][l] >= input[j][l]) { flag = false; break; }
            }
            if (flag) G[i][j] = 1;
        }
    }
}

int dp_max(int S) {
    if (vis[S]) return dmax[S];
    vis[S] = 1;
    int &ans = dmax[S];
    ans = -1;
    for (int i = 1; i <= n; i++)
        if (S >= V[i]) ans = max(ans, dp_max(S-V[i])+1);
    return ans;
}

int dp_min(int S) {
    if (vis[S]) return dmin[S];
    vis[S] = 1;
    int &ans = dmin[S];
    ans = -1;
    for (int i = 1; i <= n; i++)
        if (S >= V[i]) ans = min(ans, dp_min(S-V[i])+1);
    return ans;
}
void print_ans(int i) {
    cout << i << ' ';
    for (int j = 1; j <= k; j++) if (G[i][j] && d[i] == d[j]+1) {
        print_ans(j);
        break;
    }
}

int main() {
#ifdef LOCAL
    freopen("coins.in", "r", stdin);
    freopen("coins_1.out", "w", stdout);
#endif
    while (cin >> k >> n && n && k) {
        memset(d, 0, sizeof(d));
        memset(G, 0, sizeof(G));
        read_input();

    }
    return 0;
}