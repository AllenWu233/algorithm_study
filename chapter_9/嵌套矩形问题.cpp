// DAG模型
// 选出尽量多的矩形拍成一排，使得除了最后一个之外，每一个矩形都可以嵌套在下一个矩形内。
// 如果有多解，矩形编号的字典序应尽量小
// 分析：DAG最长路及其字典序
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100 + 10;
int n;
int G[N][N], a[N], b[N], d[N];  // d[i] 表示从结点 i 出发的最长路长度

// 读入数据并建图
void read_input() {
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[i] = min(x, y);
        b[i] = max(x, y);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] < a[j] && b[i] < b[j]) G[i][j] = 1;
}

int dp(int i) {
    int &ans = d[i];
    if (ans > 0) return ans;
    ans = 1;
    for (int j = 1; j <= n; j++)
        if (G[i][j]) ans = max(ans, dp(j)+1);  
    return ans;
}

void print_ans(int i) {
    cout << i << ' ';
    for (int j = 1; j <= n; j++) if (G[i][j] && d[i] == d[j]+1) {
        print_ans(j);
        break;
    }
}

int main() {
#ifdef LOCAL
    freopen("nested_rectangle.in", "r", stdin);
    freopen("nested_rectangle_.out", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        memset(d, 0, sizeof(d));
        memset(G, 0, sizeof(G));
        read_input();
        for (int i = 1; i <= n; i++) dp(i);
        int Max = -1, maxi = 1;
        for (int i = 1; i <= n; i++) { 
            if (d[i] > Max) {
                Max = d[i];
                maxi = i;
            }
        }
        print_ans(maxi);
        cout << "\n\n";
    }
    return 0;
}