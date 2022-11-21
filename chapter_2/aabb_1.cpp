#include <iostream>
#include <cmath>
using namespace std;
// 7744问题
int main()
{
    for (int a = 1; a <= 9; a++)
        for (int b = 0; b <= 9; b++)
        {
            int n = a*1100 + b*11;
            int m = floor(sqrt(n) + 0.5);  // 浮点误差
            if (m*m == n) cout << n << endl;
        }
    return 0;
}