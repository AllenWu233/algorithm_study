#include <cstdio>
#define INF 1000000000
using namespace std;
/*
第一行输入整数个数，第二行输入数据
 */
int main()
{
    // kase确保“相邻两行数据的输出以空行隔开，且最后一组数据以回车符结束”
    int x, n = 0, kase = 0;  
    while (scanf("%d", &n) == 1 && n)  // 鲁棒性(robustness)
    {
        int s = 0, min = INF, max = -INF;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            s += x;
            if (x < min) min = x;
            if (x > max) max = x;
        }
        if (kase) printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, double(s/n));
    }
    return 0;
}