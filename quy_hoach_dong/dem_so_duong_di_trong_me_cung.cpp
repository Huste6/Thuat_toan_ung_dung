#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int F[1001][1001];
int main(){
    int n;cin>>n;
    char a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    F[1][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]=='.'){
                if(i==1){
                    F[i][j]+=F[i][j-1];
                }else if(j==1){
                    F[i][j]+=F[i-1][j];
                }else{
                    F[i][j]+=F[i][j-1]+F[i-1][j];
                }
            }
            else F[i][j]=0;
            F[i][j]%=mod;
        }
    }
    cout<<F[n][n];
}