#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

stack<char> s;
char str[140];

int main() {
    bool failed;
    int n;
    cin >> n;
    getchar();
    while (n--) {
        failed = false;
        fgets(str, sizeof(str), stdin);  // 可以读取空串
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
                continue;
            }
            if (str[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    failed = true;
                    break;
                } else s.pop();
            } 
            if (str[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    failed = true;
                    break;
                } else s.pop();
            } 
        }
        while (!s.empty()) {
            if (s.top() == '(' || s.top() == '[') {
                failed = true;
            }
            s.pop();
        }
        if (failed) cout << "No" << endl;
        else cout << "Yes" << endl;
        memset(str, '\0', sizeof(str));
    }
}