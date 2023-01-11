#include <iostream>
#include <string>
using namespace std;

string pre, in;

struct Node {
    char v;
    Node *left, *right;
    Node() : left(NULL), right(NULL) {}
};

Node *root;

Node *newnode() { return new Node(); }  // 申请空间并执行构造函数

Node* build(string pre, string in) {  // 析构函数
    Node *root = newnode();
    root->v = pre[0];
    int i = in.find(pre[0]);
    string left_in = in.substr(0, i);
    string right_in = in.substr(i+1);
    string left_pre = pre.substr(1, left_in.length());
    string right_pre = pre.substr(left_in.length()+1);
    if (left_in.length()) root->left = build(left_pre, left_in);
    if (right_in.length()) root->right = build(right_pre, right_in);
    return root;
}

void post_order(Node *root) {
    if (root) {
        post_order(root->left);
        post_order(root->right);
        cout << root->v;
    }
}

int main() {
#ifdef LOCAL
    freopen("tree_recovery.in", "r", stdin);
    freopen("tree_recovery.out", "w", stdout);
#endif
    while (cin >> pre >> in && pre.length() && in.length()) {
        root = build(pre, in);
        post_order(root);
        cout << "\n";
    }
    return 0;
}