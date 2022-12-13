#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> dic;
map<string, int>::iterator it;

int main()
{
    string HP, ATK, DEF;
    dic[HP] = 100;
    dic[ATK] = 50;
    dic[DEF] = 35;

    cout << dic[HP] << endl;
}