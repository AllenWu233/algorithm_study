// 可重集的全排列(next_permutation版)
// Rujia Liu
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n = 5, p[5] = {8, 7, 6, 5, 4};
    sort(p, p+n);
    for (int i = 0; i < n; i++) cout << *(p+i) << " ";
    cout << endl;
    while(next_permutation(p, p+n))
    {
        for (int i = 0; i < n; i++) cout << *(p+i) << " ";
        cout << endl;
    }
    return 0;
}
