#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100][100],n;
string s="";
void Try(int i,int j){
    if(i==n && j==n) cout<<s<<endl;
    if(i+1<=n && a[i+1][j]==1){
        s+="D";
        a[i+1][j]=0;//danh dau di qua roi
        Try(i+1,j);
        s.pop_back();
        a[i+1][j]=1;
    }
    if(j+1<=n && a[i][j+1]==1){
        s+="R";
        a[i][j+1]=0;
        Try(i,j+1);
        s.pop_back();
        a[i][j+1]=1;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    Try(1,1);
    cout<<endl;
}