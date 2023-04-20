#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <string>
#include <cstring>
const int INF = 0x3f3f3f3f;
using namespace std;

const int N = 1000 + 10;
int n, f[N], len;  // f[i] 为字串 0~i 的最少回文串
string s;
bool is_palindrome[N][N];

// 初始化和预处理
void init() {
    memset(is_palindrome, 0, sizeof(is_palindrome));
    memset(f, 0, sizeof(f));
    len = s.length(); 
    for (int i = 0; i < len; i++) {  // i: 字串长度
        for (int j = 0; j+i < len; j++) {  // j: 字串起点
            int l = j, r = j + i;
            if (i == 0) is_palindrome[l][r] = 1;
            else if (i == 1) is_palindrome[l][r] = (s[l] == s[r]);
            else is_palindrome[l][r] = ((s[l] == s[r]) && is_palindrome[l+1][r-1]); 
        }
    }
    for (int i = 0; i < len; i++) f[i] = i+1;
}
// 动态规划求最少回文串
void solve() {
    for (int i = 0; i < len; i++)  // i: 取字串 0~i
        for (int j = -1; j < i; j++)
            if (is_palindrome[j+1][i]) {
                if (j == -1) f[i] = 1;  // 0~i 为回文串
                else f[i] = min(f[i], f[j]+1);
            }

    // for (int i = 0; i < len; i++) cout << f[i] << ' ';
    // cout << endl;

    cout << f[len-1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("uva11584.in", "r", stdin);
#endif
    IOS
    cin >> n;
    while (n--) {
        cin >> s;
        init();

        // for (int i = 0; i < len; i++) {
        //     for (int j = 0; j < len; j++) cout << is_palindrome[i][j] << ' ';
        //     cout << endl;
        // }

        solve();
    }
    return 0;
}