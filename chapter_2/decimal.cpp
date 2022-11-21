#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a, b, c, cnt = 0;
    double result[1000];
    while (cin >> a >> b >> c)
        if (a == 0 && b == 0 && c == 0) break;
        double da = a, db = b;
        result[cnt] = (da / db);
        cnt++;
    for (int i = 0; i < cnt; i++)
    {
        cout<<"Case "<<i+1<<" "<<result[i]<<endl;
    }
    return 0;
}