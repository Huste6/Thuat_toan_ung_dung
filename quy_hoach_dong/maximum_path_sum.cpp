#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,1};
int dy[]={0,1,1};
int main(){
    int n,m;cin>>n>>m;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1){
                a[i][j]=a[i][j];
            }else if(i==1){
                a[i][j]+=a[i][j-1];
            }else if(j==1){
                a[i][j]+=a[i-1][j];
            }else{
                a[i][j]+=max({a[i-1][j],a[i][j-1],a[i-1][j-1]});
            }
        }
    }
    cout<<a[n][m];
}