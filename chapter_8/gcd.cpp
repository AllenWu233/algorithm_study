#include <iostream>
using namespace std;
// 欧几里得算法(Euclid algorithm)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }  // 递归

int gcd2(int a, int b)  // 迭代
{
    int t;
    while (b) { t = a; a = b; b = t%b; }
    return a;
}

int main()
{
    cout << gcd(52, 26) << endl;
    cout << gcd2(52, 26) << endl;
    cout << gcd(12, 48) << endl;
    cout << gcd(13, 27) << endl;
    cout << gcd(4556, 25446560) << endl;
    cout << gcd(24854568, 24545) << endl;
}