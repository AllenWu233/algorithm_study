#include<iostream>
#include<cmath>
using namespace std;
int a[201][201],i,j,n,dp[201];
int main(){
    cin>>n;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++)
            cin>>a[i][j];
        dp[i]=1e9;//初始化数组dp，使它
    }
    for(i=n-1;i>=1;i--)//跑n上流的中转站
        for(j=i+1;j<=n;j++)//跑i下流的所有中转站
            dp[i]=min(dp[i],a[i][j]+dp[j]);//记录
    cout<<dp[1];
    return 0;
}