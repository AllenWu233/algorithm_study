#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30 + 5;
int n, kase;
int rect[N][3][3];  // [长方体编号][长方体状态编号][棱长]  状态：分别以长方体的不同棱作高
int G[N][3][N][3];  // [长方体编号][长方体状态编号][长方体编号][长方体状态编号]
int d[N][3];

// 记忆化搜索
int dp(int i, int j) {
    int &ans = d[i][j];
    if (ans > 0) return ans;
    ans = rect[i][j][2];
    for (int k = 0; k < n; k++)
        for (int l = 0; l < 3; l++)
            if (G[i][j][k][l]) ans = max(ans, dp(k, l)+rect[i][j][2]);  // 状态转移方程：d[i][j] = max(d[i][j], d[k][l] + [i][j].h)
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("uva437.in", "r", stdin);
    freopen("uva437_.out", "w", stdout);
#endif
    IOS
    while (cin >> n && n) {
        memset(G, 0, sizeof(G));
        memset(d, 0, sizeof(d));
        // 读入长方体数据
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) cin >> rect[i][0][j];
            // 长方体的三种状态
            sort(&rect[i][0][0], &rect[i][0][0]+3);
            rect[i][1][0] = rect[i][0][0], rect[i][1][1] = rect[i][0][2], rect[i][1][2] = rect[i][0][1];
            rect[i][2][0] = rect[i][0][1], rect[i][2][1] = rect[i][0][2], rect[i][2][2] = rect[i][0][0];
        }

        // // 打印 rect[][][]
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         for (int k = 0; k < 3; k++) {
        //             cout << rect[i][j][k] << ' ';
        //         }
        //         cout << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // 建图
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < n; k++)
                    for (int l = 0; l < 3; l++) {
                        if (rect[i][j][0] < rect[k][l][0] && rect[i][j][1] < rect[k][l][1]) {
                            G[i][j][k][l] = 1;
                        }
                    }

        int Max = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) Max = max(Max, dp(i, j));
        cout << "Case " << ++kase << ": maximum height = " << Max << endl;

        // 打印 d[][]
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 3; j++) cout << d[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

        // // 打印图
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         for (int k = 0; k < n; k++) {
        //             for (int l = 0; l < 3; l++) {
        //                 cout << rect[i][j][0] << ' ' << rect[i][j][1] << "-->" << rect[k][l][0] << ' ' << rect[k][l][1];
        //                 cout<<'('<<i<<','<<j<<')'<<"-->"<<'('<<k<<','<<l<<')'<<' ';
        //                 cout << G[i][j][k][l] << ' ';
        //             }
        //             cout << endl;
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }

    return 0;
}   