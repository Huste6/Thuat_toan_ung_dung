#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int main(){
    string s;cin>>s;
    int n=s.size();
    int dp[n+1];
    dp[0]=s[0]-'0';
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]*10+(i+1)*(s[i]-'0');
    }   
    ll sum=0;
    for(int i=0;i<n;i++) sum+=dp[i];
    cout<<sum;
}