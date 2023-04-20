#define IOS ios::sync_with_std(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
const int INF = 0x3f3f3f3f;
using namespace std;

const int C = 10000 + 10;
int n, c, V, W, f[C];

// 一维滚动数组
void read_input_and_solve() {
    memset(f, 0, sizeof(f));
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> V >> W;
        for (int j = c; j >= 0; j--)
            if (j >= V) f[j] = max(f[j], f[j-V] + W);
    }
}

int main() {
#ifdef LOCAL
    freopen("01bag.in", "r", stdin);
    freopen("01bag_3_.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        read_input_and_solve();
        cout << f[c] << endl;
    }
    return 0;
}
