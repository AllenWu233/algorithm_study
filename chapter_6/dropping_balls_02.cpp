#define LOCAL
#include <cstdio>

int main()
{
#ifdef LOCAL
freopen("data.in", "r", stdin);
freopen("data_02.out", "w", stdout);
#endif
    int D, I;
    while (scanf("%d%d", &D, &I) == 2)
    {
        int k = 1;
        for (int i = 0; i < D-1; i++)
            if (I%2) { k = k*2; I = (I+1)/2; }
            else { k = k*2+1; I /= 2; }
        printf("%d\n", k);
    }
    return 0;
}