#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        for (int k = 1; k <= str.length(); k++)
            for (int i = 0; i < str.length(); i += k)
            {
                if (str[i] == str[0]) continue;
                else break;
                
            }
    }
}