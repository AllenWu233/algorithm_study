#include <iostream>
using namespace std;

int n[5];

int main() {
    for (int i = 0; i < 5; i++) n[i] = i+1;
    cout << n[-1] << endl;
    cout << n[-2] << endl;
    cout << n[-3] << endl;
    cout << n[-4] << endl;
    cout << n[-10] << endl;
    cout << n[10] << endl;
    cout << n[5] << endl;
}