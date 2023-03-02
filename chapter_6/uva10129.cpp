#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int maxn = 30;
int n;
int in[maxn], out[maxn];
bool vis[maxn];
int fa[maxn];


int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool check_connected() {
    bool first = true;
    int root;
    for (int i = 1; i <= 26; i++) {
        if (vis[i]) {
            if (first) {
                root = find(i);
                first = false;
            }
            else if (find(i) != root) return false;
        } 
    }
    return true;
}

bool check_degree() {
    int cnt = 0, in_ = 0, out_ = 0;
    for (int i = 1; i <= 26; i++) {
        if (vis[i] && (in[i] != out[i])) {
            cnt++;
            if (cnt > 2) return false;
            if (out[i] - in[i] == 1) out_++;
            if (in[i] - out[i] == 1) in_++;
        }
    }
    if (cnt == 2) {
        if ((out_ == 2 && in_ == 2) || (out_ == 0 && in_ == 0))
            return false;
    }
    return true;
}

void solve() {
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 26; i++) fa[i] = i;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int u = s[0] - 'a' + 1, v = s[s.length()-1] - 'a' + 1;
        out[u]++, in[v]++;
        vis[u] = vis[v] = true;
        if (fa[v] != u) fa[u] = v;
    }
    // cout << check_connected() << endl;
    // cout << check_degree() << endl;
    if (check_connected() && check_degree()) cout << "Ordering is possible." << endl;
    else cout << "The door cannot be opened." << endl;
}

int main() {
#ifdef LOCAL
    freopen("uva10129.in", "r", stdin);
    freopen("uva10129_.out", "w", stdout);
#endif
    IOS
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
