#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

stack<char> s;

int main()
{
    bool failed;
    int n; char c;
    cin >> n;
    while (n--)
    {
        getchar();
        failed = false;
        while (c = getchar() != '\n')
        {
            if (c == '(' || c == '[') s.push(c);
            if (c == ')' && s.top() != '(') { failed = true; break; }
            else s.pop();
            if (c == '[' && s.top() != ']') { failed = true; break; }
            else s.pop();
            if (failed) cout << "No";
            else cout << "Yes" << endl;
            while (!s.empty()) s.pop();
        }
    }
}