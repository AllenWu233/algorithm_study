#include <iostream>
using namespace std;

int main()
{
    int a, b, n, m;
    cout << "输入 鸡和兔的总数量 和 总腿数：";
    while (cin >> n >> m)
    {
        a = (4 * n - m) / 2;
        b = n - a;
        if (m % 2 == 1 || a < 0 || b < 0) cout << "No answer\n";
        else cout << "鸡：" << a << "\n兔：" << b << endl;
    }
    return 0;
}