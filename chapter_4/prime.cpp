#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1) return false;
    int m = floor(sqrt(n) + 0.5);  // 修正浮点误差
    for (int i = 2; i <= m; i++)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    cout << is_prime(5) << endl;
    cout << is_prime(50) << endl;
    cout << is_prime(1) << endl;
    cout << is_prime(2) << endl;
    cout << is_prime(254524457) << endl;
    return 0;
}