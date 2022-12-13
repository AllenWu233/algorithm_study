#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 256 + 10;

// 节点类型
struct Node
{
    bool have_value;
    int v;  // 节点值
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL){}  // 构造函数
};

Node *root;  // 二叉树的根节点

Node *newnode() { return new Node(); }

bool failed;
void addnode(int v, char *s)
{
    int n = strlen(s);
    Node *u = root;  // 从根节点往下走
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (u->left == NULL) u->left = newnode();  // 节点不存在，建立新节点
            u = u->left;                               // 往左走
        }
        else if (s[i] == 'R')
        {
            if (u->right == NULL) u->right = newnode();
            u = u->right;
        }
    }
    if (u->have_value) failed = true;
    u->v = v;
    u->have_value = true;  // 别忘了做标记
}

void remove_tree(Node *u)
{
    if (u == NULL) return;  // 提前判断比较稳妥
    remove_tree(u->left);   // 递归释放左子树空间
    remove_tree(u->right);  // 递归释放右子树空间
    delete u;  // 调用u的析构函数并释放u节点本身的内存
}

char s[maxn];
bool read_input()
{
    failed = false;
    remove_tree(root);  // 释放上一棵二叉树的内存
    root = newnode();
    for (;;)
    {
        if (scanf("%s", s) != 1) return false;
        if (!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}

bool bfs(vector<int> &ans)  // 宽度优先遍历(Breadth-First Search, BFS)
{
    queue<Node*> q;
    ans.clear();
    q.push(root);  // 初始时只有一个根节点
    while (!q.empty())
    {
        Node *u = q.front(); q.pop();
        if(!u->have_value) return false;  // 有节点没有被赋值过，表明输入有误
        ans.push_back(u->v);  // 增加到输出序列尾部
        if (u->left != NULL) q.push(u->left);  // 把左子节点（如果有）放进队列
        if (u->right != NULL) q.push(u->right);  // 把右子节点（如果有）放进队列
    }
    return true;  // 输入正确
}

int main() {
    vector<int> ans;
    while(read_input())
    {
        if(!bfs(ans)) failed = 1;
        if(failed) printf("not complete\n");
        else
        {
            for(int i = 0; i < ans.size(); i++)
            {
                if(i != 0) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}