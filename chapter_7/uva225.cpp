#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const char d[4] = {'n','e','s','w'};
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
const int K = 50 + 5, N = 20 + 2;
int n, k, bx[K], by[K], ans[N], cnt;


bool check_block(int x, int y, int dir, int n) {
    int newx = x + dx[dir]*n, newy = y + dy[dir]*n;
    for (int i = 0; i < k; i++) {
        if (x == newx && x == bx[i] && min(y, newy) <= by[i] && by[i] <= max(y, newy)) return false;
        if (y == newy && y == by[i] && min(x, newx) <= bx[i] && bx[i] <= max(x, newx)) return false;
    }
    return true;
}

void solve(int x, int y, int dir, int cur) {
    if (cur > n) {
        if (x == 0 && y == 0) {
            cnt++;
            for (int i = 1; i <= n; i++) cout << d[ans[i]];
            cout << endl;
        } else return;
    } else {
        if (cur == 1) {
            for (int i = 0; i < 4; i++) {
                if (check_block(x, y, i, cur)) {
                    ans[cur] = i;
                    int newx = x + dx[i], newy = y + dy[i];
                    solve(newx, newy, i, cur+1);
                }
            }
        } else {
            for (int j = 1; j <= 3; j += 2) {
                int i = (dir + j) % 4;
                if (check_block(x, y, i, cur)) {
                    ans[cur] = i;
                    int newx = x + dx[i]*cur, newy = y + dy[i]*cur;
                    solve(newx, newy, i, cur+1);
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("uva225.in", "r", stdin);
    freopen("uva225_.out", "w", stdout);
#endif
    IOS
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < k; i++) cin >> bx[i] >> by[i];
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        solve(0, 0, 0, 1);

        // for (int i = 0; i < k; i++) cout << bx[i] << ',' << by[i] << endl;
        // for (int i = 0; i < n; i++) cout << ans[i] << ' ';
        // cout << endl;
        cout << "Found " << cnt << " golygon(s).\n\n";
    }
    return 0;
}