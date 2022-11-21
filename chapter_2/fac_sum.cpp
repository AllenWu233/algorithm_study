#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
// 阶乘之和
const int MOD = 1000000;
int fac_sum(int n)
{
    int S = 0;
    for (int i = 1; i <= n; i++)
    {
        int fac = 1;
        for (int j = 1; j <= i; j++)
            fac = (fac * j % MOD);
        S = (S + fac) % MOD;
    }
    return S;
}
int main()
{
    int n = 1000000;
    cout << fac_sum(n) << endl;
    cout<<"Time used = "<<(double)clock()/CLOCKS_PER_SEC<<setprecision(2)<<"s\n";
    return 0;
}