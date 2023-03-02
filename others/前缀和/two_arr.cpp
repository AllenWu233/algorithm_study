#include <iostream>
using namespace std;

const int maxn = 100;
int a[maxn][maxn], b[maxn][maxn];

void two_partial_sum(int a[maxn][maxn], int b[maxn][maxn], int x, int y) {
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)  // b[i][0]和b[0][j]默认为0，不会影响前缀和
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
}

int main() {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 4; j++)
            cin >> a[i][j];
    two_partial_sum(a, b, 3, 4);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 4; j++) 
            cout << b[i][j] << ' ';
        cout << endl;
    }
    return 0;
}