// n皇后问题：生成-测试法
// Rujia Liu
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;
// 先生成棋面，再判断
void search(int cur)
{
    int i, j;
    nc++;
    if(cur == n)
    {
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++)
                if(C[i] == C[j] || i-C[i] == j-C[j] || i+C[i] == j+C[j]) return;
            tot++;
        }
        else for(i = 0; i < n; i++)
        {
            C[cur] = i;
            search(cur+1);
        }
    }

int main()
{
    while (cin >> n)
    {
        double last_time = (double)clock()/CLOCKS_PER_SEC;
        memset(C, 0, sizeof(C));
        search(0);
        cout << "解的个数: " << tot << endl;
        cout << "递归次数: " << nc << endl;
        cout << "耗时：" << (double)clock()/CLOCKS_PER_SEC - last_time << "s\n";
        tot = 0; nc = 0;
    }
    return 0;
}
