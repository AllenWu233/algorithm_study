#include <iostream>
#include <cstdio>
using namespace std;
// 1/n**2 + 1/(n+1)**2 + ... + 1/m**2
int main()
{
    double sum;
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        sum = 0;
        long long ln = n;
        for (ln = n; ln <= m; ln++)
            sum += double(1.0/(ln*ln));
        printf("%.6f", sum);
    }
    return 0;
}