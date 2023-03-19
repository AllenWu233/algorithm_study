// DAG模型
// 有 n 种硬币，面值分别为 V1, V2, ... ,Vn，每种都有无限多。
// 给定非负整数 S，可以选用多少个硬币，使得面值之和恰好为 S？输出硬币数目的最小值和最大值
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int maxs = 10000 + 10;
int n, S, V[maxn], minv[maxs], maxv[maxs], min_coins[maxs], max_coins[maxs];

// 递推
void solve() {
    minv[0] = maxv[0] = 0;
    for (int i = 1; i <= S; i++) {
        minv[i] = INF, maxv[i] = -INF;
    }
    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= n; j++)
            if (i >= V[j]) {
                if (minv[i] > minv[i-V[j]] + 1) {
                    minv[i] = minv[i-V[j]] + 1;
                    min_coins[i] = j;
                }
                if (maxv[i] < maxv[i-V[j]] + 1) {
                    maxv[i] = maxv[i-V[j]] + 1;
                    max_coins[i] = j;
                }
            }
}

// void print_ans(int *d, int S) {
//     for (int i = 1; i <= n; i++)
//         if (S >= V[i] && d[S] == d[S-V[i]] + 1) {
//             cout << i << ' ';
//             print_ans(d, S-V[i]);                        
//             break;
//         }
// }

void print_ans(int *d, int S) {
    while (S) {
        cout << d[S] << ' ';
        S -= V[d[S]];
    }
}

int main() {
#ifdef LOCAL
    freopen("coins.in", "r", stdin);
    freopen("coins_2.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        memset(minv, 0, sizeof(minv));
        memset(maxv, 0, sizeof(maxv));
        memset(min_coins, 0, sizeof(min_coins));
        memset(max_coins, 0, sizeof(max_coins));

        cin >> n;
        for (int i = 1; i <= n; i++) cin >> V[i];
        cin >> S;
        solve();

        cout << minv[S] << endl;
        print_ans(min_coins, S);
        cout << endl;
        
        cout << maxv[S] << endl;
        print_ans(max_coins, S);
        cout << endl << endl;
    }
    return 0;
}