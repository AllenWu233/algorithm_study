// UVa 439
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
// 偏移量：马能走的八个方向
const int dx[8] = {-1,-2,-2,-1,1,2,2,1};
const int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int id[10][10];

int bfs(int x, int y, int x_target, int y_target) {
    if (x == x_target && y == y_target) return 0;  // 起点即终点
    queue<int> qx, qy;
    qx.push(x), qy.push(y);
    id[x][y] = 1;
    while (1) {
        x = qx.front(), y = qy.front();
        for (int i = 0; i < 8; i++) {
            int newx = x + dx[i], newy = y + dy[i];
            if (newx == x_target && newy == y_target) return id[x][y];
            if (newx < 1 || newy < 1 || newx > 8 || newy > 8 || id[newx][newy])  // 出界或已走过的点
                continue;
            qx.push(newx), qy.push(newy);
            id[newx][newy] = id[x][y] + 1;
        }
        qx.pop(), qy.pop();
    }
}

int main() {
#ifdef LOCAL
    freopen("knight_moves.in", "r", stdin);
    freopen("knight_moves.out", "w", stdout);
#endif
    string start, target;
    while (cin >> start >> target && start.length() && target.length()) {
        memset(id, 0, sizeof(id));  // 记得清零！
        cout<<"To get from "<<start<<" to "<<target<<" takes ";
        cout<<bfs(start[1]-'0', start[0]-'a'+1, target[1]-'0', target[0]-'a'+1)<<" knight moves.\n";
    }
}