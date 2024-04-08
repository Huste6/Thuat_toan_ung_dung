#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e6+1;
int dp[mod]={0};
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    for(int i=2;i<=n;i++) dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    cout<<dp[n];
}