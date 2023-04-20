#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000 + 10;
int n, s[N], d[N];
struct Node {
    int v, k, c, l;
} a[N];


bool cmp(Node a, Node b) {
    return a.v < b.v;
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i] = min(d[i], d[j] + (s[i]-s[j])*a[i].c + a[i].k);
    cout << d[n-1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("uva11400.in", "r", stdin);
    // freopen("uva11400.out", "w", stdout);
#endif
    while (cin >> n && n) {
        memset(d, 0, sizeof(0));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++)
            cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
        sort(a, a+n, cmp);
        s[0] = a[0].l;
        for (int i = 1; i < n; i++) s[i] = s[i-1] + a[i].l;
        solve();
    }
    return 0;
}