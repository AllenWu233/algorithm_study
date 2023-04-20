#define IOS ios::sync_with_std(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
const int INF = 0x3f3f3f3f;
using namespace std;

const int N = 100 + 5;
const int C = 10000 + 10;
int n, c, V, W, f[N][C];

// f[i][j]: 取前 i 个物品装到容量为 j 的背包的最大总重量
// 这种定义方式可边读入边计算
void read_input_and_solve() {
    memset(f, 0, sizeof(f));
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> V >> W;
        for (int j = 0; j <= c; j++) {
            f[i][j] = (i == 1 ? 0 : f[i-1][j]);  // 初始条件
            if (j >= V) f[i][j] = max(f[i][j], f[i-1][j-V] + W);
        }
    }
}

// 记录 V, W 的做法
// int V[N], W[N];
// void init() {
//     cin >> n >> c;
//     for (int i = 1; i <= n; i++) cin >> V[i] >> W[i];
//     memset(f, 0, sizeof(f));
// }
// // f[i][j]: 取前 i 个物品装到容量为 j 的背包的最大总重量
// void solve() {
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= c; j++) {
//             f[i][j] = (i == 1 ? 0 : f[i-1][j]);
//             if (j >= V[i]) f[i][j] = max(f[i][j], f[i-1][j-V[i]] + W[i]);
//         }
// }


int main() {
#ifdef LOCAL
    freopen("01bag.in", "r", stdin);
    freopen("01bag_2_.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        read_input_and_solve();
        cout << f[n][c] << endl;
    }
    return 0;
}
