#include <iostream>
#include <cstring>
#define maxn 1010  // 数组声明稍大点更保险
using namespace std;
int a[maxn];
int main()
{
    int n, k, first = 1;
    memset(a, 0, sizeof(a));  // 把数组a清零
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            if (j % i == 0) a[j] = !a[j];
    for (int i = 1; i <= n; i++)
        if (a[i]) { if(first) first = 0; else cout<<" "; cout<<i; }
    cout << endl;
    return 0;
}