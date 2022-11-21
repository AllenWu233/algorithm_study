/*
输入数据的每行包含若干个（至少一个）以空格隔开的整数，
输出每行所有整数之和。
只能使用字符与字符数组。
 */
/*
注意：
string很慢，sstream更慢，应谨慎使用。
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include <ctime>
#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
#endif
    string line;
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