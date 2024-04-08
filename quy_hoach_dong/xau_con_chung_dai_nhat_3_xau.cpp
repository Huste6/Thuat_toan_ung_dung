#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int F[101][101][101];
int main(){
    string s,t,k;cin>>s>>t>>k;
    int x=s.size(),y=t.size(),z=k.size();
    s='.'+s;
    t='.'+t;
    k='.'+k;
    memset(F,0,sizeof(F));
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            for(int l=1;l<=z;l++){
                if(s[i]==t[j] && t[j]==k[l]){
                    F[i][j][l]=F[i-1][j-1][l-1]+1;
                }else{
                    F[i][j][l]=max({F[i-1][j][l], F[i][j-1][l], F[i][j][l-1]});
                }
            }
        }
    }
    cout<<F[x][y][z];
}
