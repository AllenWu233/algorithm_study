#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

unordered_map<string, int> m;
const int N = 30;
const int INF = 0x3f3f3f3f;
int n, m, idx, d[N][N], G[N][N];
string ans[N];


void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] |= (d[i][k] && d[k][j])
}

void solve() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][j] == d[j][i] && d[i][j] == 1)

}

int main() {
    while (cin >> n >> m && n && m) {
        idx = 1;
        memset(d, 0, sizeof(d));
        m.clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = i == j ? 0 : INF;
        for (int i = 0; i < m; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (!m[s1]) m[s1] = idx++;
            if (!m[s2]) m[s2] = idx++;
            d[m[s1]][m[s2]] = 1;
        }
        floyd();
        solve();
    }
    return 0;
}
