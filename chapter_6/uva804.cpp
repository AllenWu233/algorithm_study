#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 110;
int NP, NT, NF, kase;
int P[maxn];  // 库所
vector<int> T[maxn];  // 变迁
map<int, int> token;  // 记录某一个变迁中库所要减少的token数

void read_input() {
    int tmp;
    for (int i = 1; i <= NP; i++) cin >> P[i];
    cin >> NT;
    for (int i = 1; i <= NT; i++)
        for (int j = 0; ; j++) {
            cin >> tmp;
            if (tmp == 0) break;
            else T[i].push_back(tmp);
        }
    cin >> NF;
}

void solve() {
    int cnt = 0;
    bool dead = false;
    while (cnt < NF) {
        int i;
        for (i = 1; i <= NT; i++) {  // 遍历所有变迁，判断是否能变迁
            bool flag = true;
            token.clear();
            int len = T[i].size();
            for (int j = 0; j < len; j++) {  // 判断具体某个变迁能否进行
                if (T[i][j] < 0) token[-T[i][j]]++;
                else break;
                if (token[-T[i][j]] > P[-T[i][j]]) { flag = false; break; }
            }
            if (!flag) continue;  // 当前变迁无法进行
            for (int j = 0; j < len; j++) {  // 变迁
                if (T[i][j] < 0) P[-T[i][j]]--;  // 输入库所可以有多个，也可以重复
                else (P[T[i][j]]++);  // 输出库所也可以有多个
            }
            break;  // 变迁成功后要从头开始遍历
        }
        if (i > NT) { dead = true; break; }
        cnt++;
    }
    if (!dead) {
        cout<<"Case "<<++kase<<": still live after "<<NF<<" transitions"<<endl;
    } else {
        cout<<"Case "<<++kase<<": dead after "<<cnt<<" transitions"<<endl;
    }
    cout<<"Places with tokens:";
    for (int i = 1; i <= NP; i++) {
        if (P[i]) cout<<' '<<i<<" ("<<P[i]<<')';
    }
    cout<<endl<<endl;
}

int main() {
#ifdef LOCAL
    freopen("uva804.in", "r", stdin);
    freopen("uva804.out", "w", stdout);
#endif
    IOS
    while (cin >> NP && NP) {
        memset(P, 0, sizeof(P));
        memset(T, 0, sizeof(T));
        read_input();
        solve();
    }
    return 0;
}
