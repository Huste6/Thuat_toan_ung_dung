#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,F[1001][1001];
int tinh(int n,int m){
    if(n==m) return 0;
    if(F[n][m]!=0) return F[n][m];
    int res=1e9;
    for(int i=1;i<=m-1;i++){
        res=min(res,tinh(n,i)+tinh(n,m-i)+1);
    }
    for(int i=1;i<=n-1;i++){
        res=min(res,tinh(i,m)+tinh(n-i,m)+1);
    }
    return F[n][m]=res;
}
int main(){
    cin>>n>>m;
    cout<<tinh(n,m);
}