// UVa442 Matrix Chain Multiplication
// Rujia Liu
// 题意：输入n个矩阵的维度和一些矩阵链乘表达式，输出乘法的次数。假定A和m*n的，B是n*p的，那么AB是m*p的，乘法次数为m*n*p
// 算法：用一个栈。遇到字母时入栈，右括号时出栈并计算，然后结果入栈。因为输入保证合法，括号无序入栈
#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

struct Matrix
{
    int a, b;
    Matrix(int a=0, int b=0) : a(a), b(b) {}
} m[26];

stack<Matrix> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
    while (cin >> expr)
    {
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(expr[i])) s.push(m[expr[i] - 'A']);
            else if (expr[i] == ')')
            {
                Matrix m2 = s.top(); s.pop();
                Matrix m1 = s.top(); s.pop();
                if (m1.b != m2.a) { error = true; break; }
                ans += m1.a * m1.b * m2.b;
                s.push(Matrix(m1.a, m2.b));
            }
        }
        if (error) printf("error\n"); else printf("%d\n", ans);
    }
    return 0;
}
/*
Sample Input
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))

Sample Output
0
0
0
error
10000
error
3500
15000
40500
47500
15125
 */