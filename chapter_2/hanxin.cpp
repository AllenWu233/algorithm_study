#include <iostream>
#include <cstdio>
using namespace std;
// a < 3, b < 5, c < 7
int main()
{
    int n = 0, a, b, c;
    while (cin >> a >> b >> c)
    {
        n++;
        for (int i = 10; i <= 100; i++)
        {
            if (i%3 == a && i%5 == b && i%7 == c)
                {
                    cout<<"Case "<<n<<": "<<i<<endl;
                    break;
                }
            if (i == 100) cout<<"Case "<<n<<": "<<"No answer"<<endl;
        }
    }
    return 0;
}