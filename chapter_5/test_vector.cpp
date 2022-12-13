#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    cout << v.empty() << endl;

    for (int i = 1; i < 11; i++) v.push_back(i);  // 在尾部添加元素
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
    cout << v.empty() << endl;

    v.pop_back();  // vector没有pop_front()
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.resize(15);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.resize(5);
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    v.clear();
    cout << v.empty() << endl;
    return 0;
}