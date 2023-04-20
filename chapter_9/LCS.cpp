#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000 + 10;
const int M = 1000 + 10;
int n, m, a[N], b[N], d[N][N];


void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    cout << d[n][m] << endl;
}

int main() {
#ifdef LOCAL
    freopen("LCS.in", "r", stdin);
    freopen("LCS_.out", "w", stdout);
#endif
    IOS
    int t;
    cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        solve();
    }
    return 0;
}