#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn][maxn], b[maxn][maxn];
int m, n;

void two_partial_sum(int a[maxn][maxn], int b[maxn][maxn], int m, int n) {
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)  // b[i][0]和b[0][j]默认为0，不会影响前缀和
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    two_partial_sum(a, b, m, n);
    int t = min(m, n) + 1;
    while (--t) {
        for (int i = 1; i <= m-t+1; i++)
            for (int j = 1; j <= n-t+1; j++) {
                if (b[i+t-1][j+t-1] - b[i+t-1][j-1] - b[i-1][j+t-1] + b[i-1][j-1] == t*t)
                    { cout << t << endl; return 0; }
            }
    }
    cout << t << endl;
    return 0;
}