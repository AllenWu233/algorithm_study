#include <iostream>
using namespace std;

int sum(int *a, int n)
{
    // 以数组作为参数调用函数时，实际上只有数组首地址传递给了函数
    //  需要另加一个参数表示元素个数
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += a[i];
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    cout << sum(a, 4) << endl;
    cout << sum(a+1, 3) << endl;  // 指针 a+1 指向 a[1]
    cout << sum(a+2, 2) << endl;
    return 0;
}