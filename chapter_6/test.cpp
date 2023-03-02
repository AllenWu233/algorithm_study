#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const int maxn = 1000 + 5;
double n,x[maxn],y[maxn],r[maxn],vis[maxn],Left,Right;

bool connect(int u,int v){
    return (r[u] + r[v]) >= sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]));
}

void check(int u){
    if(x[u] - r[u] < 0){
        Left = min(Left,y[u] - sqrt(r[u]*r[u] - x[u]*x[u]));
    }
    if(x[u] + r[u] > 1000.0){
        Right = min(Right,y[u] - sqrt(r[u]*r[u] - (1000.0 - x[u])*(1000.0 - x[u])));
    }
}

bool dfs(int u){//到达底部
    if(vis[u]){return false;}
    vis[u] = 1;
    if(y[u] - r[u] < 0){//到达底部
        return true;
    }
    for(int i = 0;i < n;i++){
        if(!vis[i] && connect(u,i) && dfs(i)){
            return true;
        }
    }
    check(u);
    return false;

}

int main(){
#ifdef LOCAL
    freopen("paintball.in", "r", stdin);
    freopen("paintball2.out", "w", stdout);
#endif
    IOS
    while(cin >> n){
        for(int i = 0;i < n;i++){
            cin >> x[i] >> y[i] >> r[i];
        }
        memset(vis,0,sizeof(vis));
        Left = Right = 1000.0;
        bool ok = true;
        for(int i = 0;i < n;i++){
            if(y[i] + r[i] >= 1000.0 && dfs(i)){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << "IMPOSSIBLE" << '\n';
        }
        else{
            cout << "0.00 " << fixed << setprecision(2) << Left;
            cout << " 1000.00 " << fixed << setprecision(2) << Right << endl;
        }
    }
    return 0;
}