#include<bits/stdc++.h>
#define faster(); ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
using ll=long long;
const int maxn=1000007;
int n,L1,L2;
ll a[maxn];
ll res;
ll dp[maxn];
int main(){
    faster();
    cin>>n>>L1>>L2;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dp[0]=a[0];
    res=dp[0];
    for(int i=1;i<n;i++){
        ll max_val=0;
        for(int j=max(0,i-L2); j<=max(0,i-L1); j++){
            if(j>=0) max_val=max(max_val,dp[j]);
        }
        dp[i]=max_val+a[i];
        res=max(dp[i],res);
    }
    cout<<res<<endl;
}