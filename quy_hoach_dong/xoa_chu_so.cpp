#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e6+7;
int main(){
    int n;cin>>n;
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=mod;
        for(char x:to_string(i)){
            dp[i]=min(dp[i],dp[i-(x-'0')]+1);
        }
    }
    cout<<dp[n];
}