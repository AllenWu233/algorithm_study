// UVa 712
// #define LOCAL
#include <iostream>
#include <string>
using namespace std;

const int maxn = 10;
int n, m;
int v[maxn]; // 映射表
string leaves;

int solve(const string &line) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (line[v[i]] == '0') ans *= 2;  // 利用二叉树的性质
        else ans = ans*2 + 1;
    }
    return leaves[ans - (1<<n)] - '0';  // 1<<n == 2**n
}

int main() {
#ifdef LOCAL
    freopen("test_s-trees.in", "r", stdin);
    freopen("test_s-trees.out", "w", stdout);
#endif
    int kase = 0;
    while (cin >> n && n) {
        cout << "S-Tree #" << ++kase << ":\n";
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            v[i] = s[1] - '0' - 1;
        }
        cin >> leaves >> m;
        string line;
        for (int i = 0; i < m; i++) {
            cin >> line;
            cout << solve(line);
        }
        cout << "\n\n";
    }
    return 0;
}