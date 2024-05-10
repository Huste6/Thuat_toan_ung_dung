#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn=1e6+1;

int n;
int a[maxn];
int dp[maxn];
int ans=-maxn;
bool ck=false;

void inp(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
}

void solve(){
    dp[0]=a[0];
    ans=dp[0];

    for(int i=1;i<n;i++){
        if(dp[i-1]>0){
            dp[i]=dp[i-1]+a[i];
        }else{
            dp[i]=max(dp[i-1],a[i]);
        }
        if(dp[i]%2==0){
            ck=true;
            ans=max(ans,dp[i]);
        }
    }
}
int main(){
    inp();
    solve();
    if(!ck) cout<<"NOT_FOUND";
    else cout<<ans;
    return 0;
}