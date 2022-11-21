#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 1, c = 0, d = 0;
    //  同一优先级的运算符，运算次序由结合方向所决定。
    if (a && b || d) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}