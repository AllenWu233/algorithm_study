#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int score = 0, n = 1, i = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'O') score += n++;
        else n = 1; 
    }
    cout << score << endl;
    return 0;
}