// n皇后问题：在n*n棋盘上放置n个皇后，使得它们互不攻击，找出所有解
// 普通回溯法
#include <iostream>
#include <cstring>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;
// C[x]表示第x行皇后的列编号
void search(int cur)
{
    nc++;  // 递归次数
    if (cur == n) tot++;  // 递归边界。只要走到了这里，所有皇后必然不冲突
    // if (cur == n)  // 打印解
    // {
    //     printf("解%d: ", tot);
    //     for (int i = 0; i < n; i++)
    //         printf("(%d,%d) ", i, C[i]);
    //     printf("\n");
    // }
    else for (int i = 0; i < n; i++)
    {
        int ok = 1;
        C[cur] = i;  // 尝试把第cur行的皇后放在第i列
        for (int j = 0; j < cur; j++)  // 检查是否和前面的皇后冲突
            // 对于(x,y),y-x值为主对角线，y+x值为副对角线
            if (C[cur] == C[j] || cur-C[cur] == j-C[j] || cur+C[cur] == j+C[j])
                { ok = 0; break; }
        if (ok) search(cur+1);  // 如果合法，则继续递归
    }
}
int main()
{
    while (cin >> n)
    {
        search(0);
        cout << "解的个数: " << tot << endl;
        cout << "递归次数: " << nc << endl;
        nc = 0; tot = 0; memset(C, 0, sizeof(C));
    }
    return 0;
}