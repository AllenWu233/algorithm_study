#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20;
int n, kase;
bool isp[maxn * 2];  // 预处理，加速判断
int A[maxn];  // 答案数组
bool vis[maxn];

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

void dfs(int cur) {
    if (cur == n && isp[A[n-1] + A[0]]) {  // 递归边界
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << "\n";
    } else {
        for (int i = 2; i <= n; i++) {  // 尝试放置每个数i
            if (!vis[i] && isp[A[cur-1] + i]) {
                A[cur] = i;
                vis[i] = true;  // 设置访问标志
                dfs(cur+1);
                vis[i] = false;  // 清除标志
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    A[0] = 1;  // 如题意，第一个数为1
    for (int i = 1; i < maxn*2; i++) {  // 生成素数表
        if (is_prime(i)) isp[i] = true;
    }
    while (cin >> n) {
        memset(vis, 0, sizeof(vis));
        if (kase > 0) cout << "\n";
        cout << "Case " << ++kase << ":\n";
        dfs(1);
    }
    return 0;
}