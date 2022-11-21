#include <iostream>
using namespace std;
// 7744问题
int main()
{
    for (int x = 1; ; x++)
    {
        int n = x * x;  // 枚举平方根，避免开平方操作
        if (n < 1000) continue;
        if (n > 9999) break;
        int hi = n / 100;
        int lo = n % 100;
        if (hi/10 == hi%10 && lo/10 == lo%10) cout << n << endl;
    }
    return 0;
}