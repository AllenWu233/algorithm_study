/*
前缀和
定义
前缀和可以简单理解为「数列的前  项的和」，是一种重要的预处理方式，能大大降低查询的时间复杂度。1

C++ 标准库中实现了前缀和函数 std::partial_sum，定义于头文件 <numeric> 中。
*/
#include <iostream>
#include <numeric>
using namespace std;

const int maxn = 1e5;
int a[maxn], b[maxn], n;

void my_partial_sum(int a[], int b[], int n) {
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = b[i-1] + a[i];
    }
}

int op(int pre_num, int num) {  // partial_sum的谓词函数
    return pre_num * num;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    my_partial_sum(a, b, n);
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    partial_sum(a, a+n, b);
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    partial_sum(a, a+n, b, op);
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << endl;
    return 0;
}