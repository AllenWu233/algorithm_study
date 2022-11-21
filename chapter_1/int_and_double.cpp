#include <iostream>
using namespace std;

const int a = 2147483647;  // int_max: 2147483647 = 2**31 - 1 
const double b = 0.1234567890123456789;  // double精度: 15~16
// double范围为-2^1024 ~ +2^1024，也即-1.79E+308 ~ +1.79E+308
int main()
{
    cout << a << endl;
    printf("%.16f\n", b);
    return 0;
}