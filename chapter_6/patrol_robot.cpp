#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 25;
int pic[maxn][maxn];  // 读入地图
bool vis[maxn][maxn][maxn];  // 访问数组，判断是否曾连续跨过若干个障碍到达某格
const int dx[4] = {0, 1, 0, -1};  // 偏移量
const int dy[4] = {1, 0, -1, 0};
int t, m, n, k;

struct Node {
    int x;
    int y;
    int step;  // 当前步数
    int cnt;  // 当前连续跨越障碍的数量
};

void read_lines() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> pic[i][j];   
}

bool check(int x, int y) {  // 检查是否出界
    if (x < 1 || y < 1 || x > m || y > n) return true;
    return false;
}

int bfs(int x, int y, int k) {
    Node t = {x, y, 0, 0};
    queue<Node> q;
    q.push(t);
    while (!q.empty()) {
        t = q.front();
        if (t.x == m && t.y == n) return t.step;
        for (int i = 0; i < 4; i++) {
            int px = t.x + dx[i], py = t.y + dy[i];
            if (check(px, py)) continue;  // 出界
            Node tmp = {px, py, t.step, t.cnt};  // 一定要用临时变量来操作！
            if (pic[px][py]) tmp.cnt++;  // 该格为障碍
            else tmp.cnt = 0;  // 该格为空地
            if (tmp.cnt <= k && !vis[px][py][tmp.cnt]) {  // 连续跨越障碍数量<=k且未曾连续跨过t.cnt个障碍到达(px,py)
                tmp.step++;
                vis[px][py][tmp.cnt] = true;  // 已访问
                q.push(tmp);
            }
        }
        q.pop();
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("patrol_robot.in", "r", stdin);
    freopen("patrol_robot.out", "w", stdout);
#endif
    ios::sync_with_stdio(false); //取消cin与stdin的同步，加速输入输出
    cin.tie(0);  // 解除cin与cout的绑定，进一步加快执行效率
    cout.tie(0);
    cin >> t;
    while (t--) {
        memset(vis, false, sizeof(vis));  // 记得清零！
        read_lines();
        cout << bfs(1, 1, k) << "\n";
    }
    return 0;
}