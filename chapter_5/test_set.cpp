#include <iostream>
#include <set>
using namespace std;

set<int> num;
set<int>::iterator it;

int main()
{
    num.insert(100);
    num.insert(5);
    num.insert(54);
    num.insert(42);
    num.insert(1);
    for (it = num.begin(); it != num.end(); it++)
        cout << *it << " ";
    cout << endl;
    num.insert(42);
    for (it = num.begin(); it != num.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << num.count(42) << endl;

    num.erase(42);
    for (it = num.begin(); it != num.end(); it++)
        cout << *it << " ";
    cout << endl;
}