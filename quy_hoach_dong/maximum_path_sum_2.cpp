#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int dp[n+1][n+1];
    int ans=0;
    for(int i=1;i<=n;i++){
        dp[1][i]=a[1][i];
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==1){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]) + a[i][j];
            }else if(j==n){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
            }else{
                dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
}