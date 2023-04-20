#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 200 + 10;
int n;
int Min = 0x3f3f3f3f;
int adj[maxn][maxn];


void dfs(int u, int sum) {
    if (u == n) Min = min(Min, sum);
    else for (int v = u+1; v <= n; v++) {
        if (sum < Min) {  // 若当前和大于等于最小和，则剪枝
            dfs(v, sum+adj[u][v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    dfs(1, 0);
    cout << Min;
    return 0;
}