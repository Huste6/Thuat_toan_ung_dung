#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int F[n+1][m+1];
    s='.'+s;
    t='.'+t;
    memset(F,0,sizeof(F));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                F[i][j]=F[i-1][j-1]+1;
            }else F[i][j]=max(F[i-1][j],F[i][j-1]);
        }
    }
    cout<<F[n][m];
}