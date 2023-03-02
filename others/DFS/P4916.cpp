#include <iostream>
using namespace std;

const int maxn = 1000 + 10;
int n, m, bv;
int pic[maxn][maxn];
bool vis[maxn][maxn];
const int dx[] = {-1,0,1,-1,1,-1,0,1};
const int dy[] = {-1,-1,-1,0,0,1,1,1};


bool check(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    return true;
}

void init_num(int x, int y) {
    if (pic[x][y] == 1) return;
    for (int i = 0; i < 8; i++) {
        int newx = x + dx[i], newy = y + dy[i];
        if (check(newx, newy)) {
            if (pic[newx][newy] == 1) {
                pic[x][y] = 2;
                break;   
            }
        } 
    }
}

bool dfs(int x, int y) {
    if (vis[x][y] || pic[x][y]) return false;
    vis[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int newx = x + dx[i], newy = y + dy[i];
        if (check(newx, newy) && vis[newx][newy] == 0) {
            dfs(newx, newy);
        } 
    }
    return true;     
}

void check_num(int x, int y) {
    if (pic[x][y] == 1 || pic[x][y] == 0) return;
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        int newx = x + dx[i], newy = y + dy[i];
        if (check(newx, newy) && pic[newx][newy] == 0) {
            flag = false;
            break; 
        }
    }
    if (flag) bv++;
}

int main() {
#ifdef LOCAL
    freopen("P4916.in", "r", stdin);
    freopen("P4916_.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> pic[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) init_num(i, j);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dfs(i, j)) bv++;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) check_num(i, j);

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << pic[i][j] << " ";
    //     cout << endl;
    // }
    
    cout << bv << endl;
    return 0;
}
