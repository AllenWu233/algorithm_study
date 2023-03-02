#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define LL long long
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

map<LL, int> cnt;  // map映射：记录num*2**depth重复的次数

int solve(string s) {
    int depth = 0, sum = 0, maxn = 0;  // 二叉树深度，结点总数，不需更改的结点数
    int len = s.length();
    for (int i = 0; i < len; i++)

     {
        if (s[i] == '[') depth++;
        if (s[i] == ']') depth--;
        if (isdigit(s[i])) {
            LL num = 0;
            for (; isdigit(s[i]); i++) { num *= 10; num += s[i] - '0'; }  // 字符转整数
            i--;  // 防止for循环导致的差1错误
            sum++;
            cnt[num << depth]++;  // cnt[num*2**depth]++
            maxn = max(maxn, cnt[num << depth]);
        }
    }
    return sum - maxn;
} 

int main() {
#ifdef LOCAL
    freopen("uva12166.in", "r", stdin);
    freopen("uva12166_.out", "w", stdout);
#endif
    IOS
    int t;
    string s;
    cin >> t;
    while (t--) {
        cnt.clear();
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
