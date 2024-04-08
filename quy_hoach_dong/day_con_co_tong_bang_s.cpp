#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
/*c1
int main(){
    int n,s;cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bool dp[s+1];
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=s;j>=a[i];j--){
            if(dp[j-a[i]]){
                dp[j]=true;
            }
        }
    }
    if(dp[s]) cout<<"1";
    else cout<<"0"; 
}*/
bool F[201][1001];
int main(){
    int n,s;cin>>n>>s;
    int a[n];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) {
        F[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j>=a[i]){
                F[i][j]=F[i-1][j-a[i]] || F[i-1][j];
            }else F[i][j]=F[i-1][j];
        }
    }
    cout<<F[n][s];
}