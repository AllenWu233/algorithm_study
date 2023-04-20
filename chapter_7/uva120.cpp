#define IOS ios::sync_with_stdin(false);cin.tie(0);cout.tie(0);
#define _all(x) x.begin(), x.end()

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, k, done, idx;
vector<int> a, tmp;


void solve() {
    if (done == 0 && a[0] == tmp[0]) { cout << 0; return; }
    for (int i = done-1; i >= 0; i--) {
        if (a[i] == tmp[done-1]) {
            if (i != done-1) {
                if (i == 0) {
                    reverse(a.begin(), a.begin()+done);
                    cout << idx - done + 1 << ' ';
                } else {
                    reverse(a.begin(), a.begin()+done);
                    reverse(_all(a));
                    cout << i + 1  << ' ' << idx - done + 1 << ' ';
                }
            }
            done--;
            solve();
        }
    } 
}

int main() {
    string line;
    while (getline(cin, line)) {
        a.clear();
        tmp.clear();
        stringstream ss(line);
        int t;
        while (ss >> t) { a.emplace_back(t); tmp.emplace_back(t); }
        sort(_all(tmp));
        idx = a.size();
        done = idx;
        solve();
//        cout << "\n";
//        for (auto &i : a) cout << i << ' ';
//        cout << "\n";
        cout << "\n";
    }
    return 0;
}
