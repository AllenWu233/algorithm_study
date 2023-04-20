#define IOS ios::sync_with_stdin(fasle);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
const int INF = 0x3f3f3f3f;
using namespace std;

const int M = 10 + 2, N = 100 + 5;
int d[M][N], a[M][N], nxt[M][N];
int ans, first, m, n;


void init() {
    ans = INF, first = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
}

void solve() {
    for (int j = n-1; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            if (j == n-1) d[i][j] = a[i][j];
            else {
                int rows[3] = {i, i-1, i+1};
                if (i == 0) rows[1] = m-1;
                if (i == m-1) rows[2] = 0;
                sort(rows, rows+3);
                d[i][j] = INF;
                for (int k = 0; k < 3; k++) {
                    int v = d[rows[k]][j+1] + a[i][j];
                    if (v < d[i][j]) {
                        d[i][j] = v;
                        nxt[i][j] = rows[k];
                    }
                }
            }
            if (j == 0 && d[i][j] < ans) {
                ans = d[i][j];
                first = i;
            }
        }
        cout << first+1;
        for (int i = nxt[first][0], j = 1; j < n; i = nxt[i][j], j++)
            cout << ' ' << i+1;
        cout << endl << ans << endl;
    }
}

int main() {
    init();
    solve();
}