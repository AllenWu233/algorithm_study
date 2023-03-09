#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int d[N][N], a[N][N];
int n;


// 递推
void solve() {
    for (int i = 1; i <= n; i++) d[n][i] = a[n][i];
    for (int i = n-1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            d[i][j] = a[i][j] + max(d[i+1][j], d[i+1][j+1]);
    cout << d[1][1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("number_triangle.in", "r", stdin);
    freopen("number_triangle_1.out", "w", stdout);
#endif
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++) cin >> a[i][j];
        solve();
    }
    return 0;
}