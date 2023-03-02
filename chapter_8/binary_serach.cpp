#include <iostream>
#include <algorithm>
using namespace std;

int binary_serach(int *A, int x, int y, int v)
{   // 一般把二分查找写为非递归
    int m;
    while (x < y)
    {
        m = x + (y-x)/2;
        if (A[m] == v) return m;
        else if (A[m] > v) y = m;
    }
    return -1;
}
int main()
{
    int arr[] = {453, 3, 53453, 687, 1234, 45, 5452};
    sort(arr, arr+6);
    cout << binary_serach(arr, 0, 6, 687) << endl;
    for (int i = 0; i < 7; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}