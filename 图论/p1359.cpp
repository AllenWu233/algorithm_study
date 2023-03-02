#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
int a[maxn][maxn];
int dp[maxn];


void solve() {
    for (int i = n-1; i >= 1; i--)  // 跑n上流的中转站
        for (int j = i+1; j <= n; j++)  // 跑i下流的所有中转站
            dp[i] = min(dp[i], dp[j]+a[i][j]);  // 记录
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            cin >> a[i][j];
    memset(dp, 0x3f, sizeof(dp));  // 初始化数组dp
    dp[n] = 0;  // 务必保证！
    solve();
    cout << dp[1];
    return 0;
}