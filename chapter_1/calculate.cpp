#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    cout << (8.0 / 5.0) << endl;
    printf("%.0f\n", 8.0 / 5.0);
    printf("%.1f\n", 8.0 / 5.0);
    printf("%.2f\n", 8.0 / 5.0);
    printf("%.3f\n", 8.0 / 5.0);
    printf("%f\n", 8.0 / 5.0);
    printf("%d\n", 8 / 5);

    printf("%.8f\n", 1 + 2 * sqrt(3) / (5 - 0.1));
    printf("%f\n", sqrt(9.0));
    printf("%f\n", acos(-1.0));  // arccox()
    return 0; 
}