// n皇后问题：优化的回溯法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int C[50], vis[3][50], tot = 0, n = 8, nc = 0;
// 利用二维数组vis[2][]直接判断当前尝试的皇后所在的列和两个对角线是否已有其他皇后
void search(int cur)
{
    int i, j;
    nc++;
    if (cur == n) tot++;
    // if(cur == n)
    // {
    //     printf("解%d: ", tot);
    //     for (int i = 0; i < n; i++)
    //         printf("(%d,%d) ", i, C[i]);
    //     printf("\n");
    // }
    else for(i = 0; i < n; i++)
    {
        if (!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
        {
            C[cur] = i;  // 如果不用打印解，整个C数组都可以省略
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
            search(cur+1);
            vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
        }
    }
}

int main() {
    while (cin >> n)
    {
        memset(vis, 0, sizeof(vis));
        search(0);
        cout << "解的个数: " << tot << endl;
        cout << "递归次数: " << nc << endl;
        tot = 0; nc = 0;
    }
    return 0;
}
