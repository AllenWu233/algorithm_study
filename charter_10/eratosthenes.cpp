// 埃氏筛法
#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100;
bool vis[MAXN];

void init_prime(int n) {
    vis[0] = 1, vis[1] = 1;
    int m = sqrt(n+0.5);
    for (int i = 2; i <= m; i++) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = true;
}

int main() {
    init_prime(MAXN);
    for (int i = 0; i < MAXN; i++) if (!vis[i]) 
        cout << i << ' ';
    cout << endl;
    return 0;
}