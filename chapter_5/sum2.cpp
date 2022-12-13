#include <iostream>
using namespace std;
#include <ctime>
#define LOCAL
// 待完善
int main()
{
#ifdef LOCAL
    freopen("sum2.in", "r", stdin);
    freopen("sum2.out", "w", stdout);
#endif
    while (getline(cin, line))  // 读取一行数据
    {
        int sum = 0, x;
        stringstream ss(line);  // ss:字符串流
        while (ss >> x) sum += x;
        cout << sum << "\n";
        cout << "Time use = " << clock() << "ms\n\n";
    }
    return 0;
} 