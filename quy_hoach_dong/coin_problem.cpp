#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int F[1001][1001];
int main(){
    int n,s;
    cin>>n>>s;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=s;i++) F[0][i]=1e9;
    F[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){ 
            if(j>=a[i]){
                F[i][j]=min(F[i][j-a[i]]+1,F[i-1][j]);
            } else {
                F[i][j]=F[i-1][j];
            }
        }
    }
    if(F[n][s]!=1e9) cout<<F[n][s];
    else cout<<-1;
}
