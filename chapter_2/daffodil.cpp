#include <iostream>
#include <cmath>
using namespace std;
// 水仙花数
int main()
{
    for (int i = 100; i < 999; i++)
    {
        int a = i/100, b = (i - a*100) / 10, c = i - a*100 - b*10;
        if (i == pow(a,3) + pow(b,3) + pow(c,3)) cout << i << endl;
    }
    return 0;
}