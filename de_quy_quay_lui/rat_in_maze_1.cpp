#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100][100],x[100][100],n;
string s="";int ok=0;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
string path="DLRU";
void Try1(int i,int j){
    if(i==n && j==n){
        cout<<s<<endl;
        ok=1;
    }
    for(int k=0;k<4;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<= n && j1>=1 && j1<=n && a[i1][j1] == 1){
            s+=path[k];
            a[i1][j1]=0;
            Try1(i1,j1);
            a[i1][j1]=1;
            s.pop_back();
        }
    }
}
void Try(int i,int j){
    if(i==n && j==n){
        cout<<s<<endl;
        ok=1;
    }
    if(i+1<=n && a[i+1][j]==1){
        s+="D";
        a[i+1][j]=0;
        Try(i+1,j);
        s.pop_back();
        a[i+1][j]=1;
    }
    if(j-1>=1 &&  a[i][j-1]==1){
        s+="L";
        a[i][j-1]=0;
        Try(i,j-1);
        s.pop_back();
        a[i][j-1]=1;
    }
    if(j+1<=n && a[i][j+1]==1 ){
        s+="R";
        a[i][j+1]=0;
        Try(i,j+1);
        s.pop_back();
        a[i][j+1]=1;
    }
    if(i-1>=1 && a[i-1][j]==1){
        s+="U";
        a[i-1][j]=0;
        Try(i-1,j);
        s.pop_back();
        a[i-1][j]=1;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(a[1][1] && a[n][n]){
        a[1][1]=0;
        Try(1,1);
    }
    cout<<endl;
}