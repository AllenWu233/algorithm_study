#include <cstdio>
#define INF 1000000000
/*
在算法竞赛中，如果不允许使用重定向方式读写数据，
应使用 fopen 和 fscan/fprintf 进行输入输出
 */
int main()
{
    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");

    int x, n = 0, min = INF, max = -INF, s = 0;
    while (fscanf(fin, "%d", &x) == 1)  // fscanf()
    {
        s += x;
        if (x < min) min = x;
        if (x > max) max = x;
        /* 输出中间结果的测试语句 */
        // fprintf(fout, "x = %d, min = %d, max = %d\n", x, min, max);
        n++;
    }
    fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);  // fprintf()
    
    fclose(fin);
    fclose(fout);
    return 0;
}