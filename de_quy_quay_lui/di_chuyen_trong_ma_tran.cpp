#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100][100];
int dx[2]={0,1};
int dy[2]={1,0};
int visited[100][100],n,m,cnt=0;
void ktao(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    memset(visited,0,sizeof(visited));
}
void Try(int i,int j){
    if(i==n && j==m) cnt++;
    for(int k=0;k<2;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=m && visited[i1][j1]==0){
            visited[i1][j1]=1;
            Try(i1,j1);
            visited[i1][j1]=0;
        }
    }
}
int main(){
    ktao();
    Try(1,1);
    cout<<cnt<<endl;
}