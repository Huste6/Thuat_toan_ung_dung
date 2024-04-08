#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;int F[1001][1001];
int main(){
    int n,s;cin>>n>>s;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) F[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j>=a[i]){
                F[i][j]=F[i][j-a[i]]+F[i-1][j];
            }else F[i][j]=F[i-1][j];
            F[i][j]%=mod;
        }
    }
    cout<<F[n][s];
}