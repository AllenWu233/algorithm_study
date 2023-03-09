#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1010;
int d[N][N], a[N][N];
int n;


// 记忆化搜索
int solve(int i, int j) {
    if (d[i][j] >= 0) return d[i][j];
    return d[i][j] = a[i][j] + (i == n ? 0 : max(solve(i+1, j), solve(i+1, j+1)));
}

int main() {
#ifdef LOCAL
    freopen("number_triangle.in", "r", stdin);
    freopen("number_triangle_2.out", "w", stdout);
#endif
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) cin >> a[i][j];
        memset(d, -1, sizeof(d));
        cout << solve(1, 1) << endl;
    }
    return 0;
}