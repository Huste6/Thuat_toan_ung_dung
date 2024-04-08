#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
int main(){
    int n;cin>>n;
    int a[n];
    int dp[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j] < a[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<n-*max_element(dp,dp+n);
}