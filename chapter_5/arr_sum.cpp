#include <iostream>
#include <algorithm>
using namespace std;
// const int maxn = 100 + 10;
// int A[maxn];
int main()
{
    long long a, b;
    while (cin >> a >> b)
    {
        cout << "最小值：" << min(a, b) << "\n";
    }
    return 0;
}


/*
// or:
#include <iostream>
#include <algorithm>
// using namespace std;
// const int maxn = 100 + 10;
// int A[maxn];
int main()
{
    long long a, b;
    while (std::cin >> a >> b)
    {
        std::cout << std::min(a, b) << "\n";
    }
    return 0;
} */