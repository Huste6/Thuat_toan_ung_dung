#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int F[1001][1001];
int main(){
    int n,m;cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                F[i][j]=min({F[i-1][j],F[i][j-1],F[i-1][j-1]})+1;
                ans=max(ans,F[i][j]);
            }
            else F[i][j]=0;
        }
    }
    cout<<ans<<endl;
}