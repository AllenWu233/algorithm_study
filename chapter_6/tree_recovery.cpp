#include <iostream>
#include <string>
using namespace std;

// const int maxn 30;
string preord, inord;

struct Node
{
    bool have_value;
    char v;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {}
};

Node *root;

Node *newnode() { return new Node(); }

int build(root, string preord, string inord)
{
    ;
}