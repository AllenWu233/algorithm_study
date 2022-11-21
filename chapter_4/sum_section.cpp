#include <iostream>
using namespace std;

int sum(int *begin, int *end)
{
    int n = end - begin;
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += begin[i];
    return ans;
}
int sum2(int *begin, int *end)
{
    int *p = begin;
    int ans = 0;
    for (int *p = begin; p != end; p++)
        ans += *p;
    return ans;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << sum(a+1, a+6) << endl;
    cout << sum2(a+1, a+6) << endl;
    return 0;
}