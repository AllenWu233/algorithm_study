#define IOS ios::sync_with_std(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
const int INF = 0x3f3f3f3f;
using namespace std;

const int N = 100 + 5;
const int C = 10000 + 10;
int n, c, V[N], W[N], d[N][C];


void init() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> V[i] >> W[i];
    memset(d, 0, sizeof(d));
}
// d[i][j]: 取第 i 个物品、背包剩余容量为 j 时还能取得的最大重量
void solve() {
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= c; j++) {
            d[i][j] = (i == n ? 0 : d[i+1][j]);
            if (j >= V[i]) d[i][j] = max(d[i][j], d[i+1][j-V[i]] + W[i]);
        }
}

int main() {
#ifdef LOCAL
    freopen("01bag.in", "r", stdin);
    freopen("01bag_1_.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
        cout << d[1][c] << endl;
    }
    return 0;
}
