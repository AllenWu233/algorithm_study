#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <string>
#include <>
using namespace std;

struct Node {
    int v;
    Node *left, *right;
    Node() : left(NULL), right(NULL){}
};

Node *root;
Node *newnode() { return new Node(); }

int solve(string s) {
    if (s[0] != '[') return 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            Node node = newnode();
            root->left = node;
            root = root->left;          
        }
    }
} 

int main() {
#ifdef LOCAL
    freopen("uva12166.in", "r", stdin);
    freopen("uva12166.out", "w", stdout);
#endif
    IOS
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}
