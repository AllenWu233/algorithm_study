#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定一个后缀表达式，返回它的结果
     * @param str string字符串 
     * @return long长整型
     */
    long long legalExp(string str) {
        // write code here
        string str_num;
        stack<long long> s;
        for (int i = 0; i < size(str); i++)
        {
            if (str[i] == '#')
            {
                long long num = stoll(str_num);
                s.push(num);
                str_num = "";
                num = 0;
            }
            else if (str[i] == '+')
            {
                long long a, b;
                { a = s.top(); s.pop(); }
                { b = s.top(); s.pop(); }
                s.push(a + b);
            }
            else if (str[i] == '-')
            {
                long long a, b;
                { a = s.top(); s.pop(); }
                { b = s.top(); s.pop(); }
                s.push(b - a);
            }
            else if (str[i] == '*')
            {
                long long a, b;
                { a = s.top(); s.pop(); }
                { b = s.top(); s.pop(); }
                s.push(a * b);
            }
            else str_num += str[i];

        }
        return s.top();
    }
};
int main()
{
    Solution sl;
    cout << sl.legalExp("59455#696574#*45646#-") << endl;
    return 0;
}