#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
int main(){
    int n,k;
    cin>>n>>k;
    ll dp[n+1]={0};dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(i,k);j++){
            dp[i]+=dp[i-j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
}