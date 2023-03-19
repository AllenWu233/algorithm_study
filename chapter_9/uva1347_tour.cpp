#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

// 原题可转化为：两人从同一起点出发，每次其中一人走动，最后都走到终点
const int N = 1010;
int n;
double dis[N][N];  // 图存储各点之间的距离
double f[N][N];  // 表示 1~max(i, j) 全部走过，且两人当前位置为i和j,还需走多长的距离
                 // f 的第一个坐标表示当前走动的人的位置


struct Node {
    int x, y;
} P[N];

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void init() {
    for (int i = 1; i <= n; i++)
        cin >> P[i].x >> P[i].y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = dist(P[i].x, P[i].y, P[j].x, P[j].y);
    for (int i = 1; i <= n; i++)
        f[n-1][i] = dis[n-1][n] + dis[i][n];  // 边界条件：表示所有点都走过了，两人只需直接走到终点
}

void solve() {
    for (int i = n-2; i >= 1; i--)
        for (int j = 1; j < i; j++)
            f[i][j] = min(f[i+1][j] + dis[i][i+1], f[i+1][i] + dis[j][i+1]);  // 状态转移方程：只允许其中一人走到 i+1, 不允许走到 i+2, i+2...能够表示其状态的同时防止漏解
}


int main() {
#ifdef LOCAL
    freopen("uva1347.in", "r", stdin);
    freopen("uva1347_.out", "w", stdout);
#endif
    while (cin >> n && n) {
        init();
        solve();
        double ans = dis[1][2] + f[2][1];  // 所求结果；第一步一定有一个人走到了 2 点
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}