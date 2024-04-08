#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int dp[n+1];
    int ans=0;
    memset(dp,0,sizeof(dp));   
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        for(int j=i-1;j>=1;j--){
            if(a[i]>=a[j]){
                dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
