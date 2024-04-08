#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int dp[10001];
int main(){
    int n,s;cin>>n>>s;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            if(i>=a[j]){
                dp[i]+=dp[i-a[j]];
            }
            dp[i]%=mod;
        }
    }
    cout<<dp[s];
}