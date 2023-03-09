#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn][maxn];
int d[maxn][maxn];
int n;

bool read_input() {
    if (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                cin >> a[i][j];
        return true;
    } return false;
}

int solve(int i, int j) {
    if (d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i == n ? 0 : max(solve(i+1, j), solve(i+1, j+1)));
}

int main() {
#ifdef LOCAL
    freopen("number_triangle.in", "r", stdin);
    freopen("number_triangle_.out", "w", stdout);
#endif
    IOS
    while (read_input()) {
        memset(d, -1, sizeof(d));
        cout << solve(1, 1) << endl;
    }
    return 0;
}