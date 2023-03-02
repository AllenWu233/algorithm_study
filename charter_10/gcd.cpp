#include <iostream>
using namespace std;
// 欧几里得算法(Euclid algorithm)  最大公约数
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }  // 递归

int gcd2(int a, int b) {  // 迭代 
    int t;
    while (b) { t = a; a = b; b = t%b; }
    return a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }  // 最小公倍数；先除后乘防溢出

int main() {
    // cout << gcd(52, 26) << endl;
    // cout << gcd2(52, 26) << endl;
    // cout << gcd(4556, 25446560) << endl;
    // cout << gcd(24854568, 24545) << endl;
    // cout << lcm(4, 24) << endl;
    int a, b;
    while (cin >> a >> b && a && b) cout << lcm(a, b) << endl;
    return 0;
}