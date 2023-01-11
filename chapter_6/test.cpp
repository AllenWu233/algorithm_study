#include <iostream>
using namespace std;

int main() {
    int cnt = 1;
    int i;
    for (i = 2; cnt != 1500; i++) {
        if (!(i%2 == 0 || i%3 == 0 || i%5 == 0)) continue;
        bool flag = true;
        for (int j = 2; j < i; j++)
            if (i%j == 0 && j != 2 && j != 3 && j != 5) { flag = false; break; }
        if (flag) cnt++;
    }
    cout << i << endl;
}