#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 30 + 5;
int k, n;
int d[N];  // d[i] 表示从结点 i 出发的最长路长度
int G[N][N], input[N][N];

// 读入数据并建图
void read_input() {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) cin >> input[i][j];
        sort(&input[i][1], &input[i][1] + n);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            bool flag = true;
            for (int l = 1; l <= n; l++) {
                if (input[i][l] >= input[j][l]) { flag = false; break; }
            }
            if (flag) G[i][j] = 1;
        }
    }
}

int dp(int i) {
    int &ans = d[i];
    if (ans > 0) return ans;
    ans = 1;
    for (int j = 1; j <= k; j++)
        if (G[i][j]) ans = max(ans, dp(j)+1);  
    return ans;
}

void print_ans(int i) {
    cout << i << ' ';
    for (int j = 1; j <= k; j++) if (G[i][j] && d[i] == d[j]+1) {
        print_ans(j);
        break;
    }
}

int main() {
#ifdef LOCAL
    freopen("uva103.in", "r", stdin);
    freopen("uva103_.out", "w", stdout);
#endif
    while (cin >> k >> n && n && k) {
        memset(d, 0, sizeof(d));
        memset(G, 0, sizeof(G));
        read_input();

        // for (int i = 1; i <= k; i++) {
        //     for (int j = 1; j <= n; j++) cout << input[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

        for (int i = 0; i < k; i++) dp(i);
        int Max = -1, maxi = 1;
        for (int i = 0; i < k; i++) { 
            if (d[i] > Max) {
                Max = d[i];
                maxi = i;
            }
        }
        cout << Max << endl;
        print_ans(maxi);
        cout << endl;
    }
    return 0;
}