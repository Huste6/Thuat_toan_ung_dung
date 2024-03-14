#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100][100],n;
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
void Try(int i,int j){
    //cout<<i<<" "<<j;
    a[i][j]=0;
    for(int k=0;k<4;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]){
            Try(i1,j1);
        }
    } 
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(a[i][j]){
                ++cnt;
                Try(i,j);//loang ra cac mien chua 1
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}