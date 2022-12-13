#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        stack<int> s;
        int A = 1, B = 1;
        for (int i = 1; i <= n; i++)
            scanf("%d", &target[i]); 
        int ok = 1;
        while (B <= n)
        {
            if (A == target[B]) { A++; B++; }  // 入栈顺序与出栈一致
            else if (!s.empty() && s.top() == target[B]) { s.pop(); B++; }  // 入栈
            else if (A <= n) s.push(A++);  // 出栈
            else { ok = 0; break; }  // 不合法
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}
/*
「示例」
入栈：(1 2 3 4 5)
出栈：(1 2 3 4 5)
     (1 2 3 5 4)
     (5 4 3 2 1)
     ......
 */