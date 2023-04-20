#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1000 + 10;
int a[N], d[N], n;


void solve() {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) d[i] = d[j] + 1;  // 最长上升子序列（LIS, longest increasing subsequence）
            // if (a[j] <= a[i]) d[i] = max(0, d[j]) + 1;  // 最长不下降子序列(LNDS, longest non descending subsequence)

    // 结果为 max{d[i]}
    int Max = -INF;
    for (int i = 0; i < n; i++) Max = max(Max, d[i]);
    cout << Max << endl;
    // for (int i = 0; i < n; i++) cout << d[i] << ' ';
    // cout << endl;
}

int main() {
#ifdef LOCAL
    freopen("LIS.in", "r", stdin);
    // freopen("LIS_.out", "w", stdout);
#endif
    IOS
    int t;
    cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        d[0] = 1;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        solve();
    }
    return 0;
}