#include <iostream>
using namespace std;
// http://en.wikipedia.org/wiki/3n+1
int main()
{
    /* C间接输入输出long long int
       因为直接输入不保险
    int n2;
    scanf("%d", n2);
    long long n = n2;
     */ 
    int cnt = 0;
    long long n;  // int会乘法溢出 n <= 10**9
    cin >> n;
    while (n > 1)
    {
        if (n % 2 == 1) n = n*3 - 1;
        else n /= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}