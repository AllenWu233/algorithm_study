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
int n, S, V[maxn], minv[maxs], maxv[maxs];
int min_coin[maxs], max_coin[maxs];  // 空间换时间


void init() {
    memset(minv, INF, sizeof(minv));
    memset(maxv, -INF, sizeof(maxv));
    memset(min_coin, 0, sizeof(min_coin));
    memset(max_coin, 0, sizeof(max_coin));
    minv[0] = maxv[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> V[i];
    cin >> S;
}
// 递推
void solve() {
    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= n; j++)
            if (i >= V[j]) {
                if (minv[i] > minv[i-V[j]] + 1) {
                    minv[i] = minv[i-V[j]] + 1;
                    min_coin[i] = j;
                }
                if (maxv[i] < maxv[i-V[j]] + 1) {
                    maxv[i] = maxv[i-V[j]] + 1;
                    max_coin[i] = j;
                }
            }
}

void print_ans(int *v, int *d, int S) {
    cout << v[S] << endl;
    while (S && d[S]) {
        cout << V[d[S]] << ' ';
        S -= V[d[S]];
    }
    cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("coins.in", "r", stdin);
    // freopen("coins_2.out", "w", stdout);
#endif
    IOS
    int t;
    cin >> t;
    int kase = 0;
    while (t--) {
        init();
        solve();
        cout << "Case " << ++kase << ":\n";
        print_ans(minv, min_coin, S);
        print_ans(maxv, max_coin, S);

        // for (int i = 0; i <= S; i++) cout << min_coin[i] << ' ';
        // cout << endl;
        // for (int i = 0; i <= S; i++) cout << max_coin[i] << ' ';
        // cout << endl;

        // cout << endl;
    }
    return 0;
}