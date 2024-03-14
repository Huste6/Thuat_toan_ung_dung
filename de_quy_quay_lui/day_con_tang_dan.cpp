#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,a[100];
int x[100];
int cnt=0;
bool visited[100];
vector<vector<int>> vt;
void inp(){
    memset(visited,false,sizeof(visited));
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void Try(int i,int pos){
    if(i >= 3){
        vector<int> tmp(x+1,x+i);
        vt.push_back(tmp);
    }
    for(int j=pos;j<=n;j++){
        if(!visited[j]){
            visited[j]=true;
            x[i]=a[j];
            if (a[j] > x[i-1]) Try(i+1,j+1);
            visited[j]=false;
        }
    }
}
int main(){
    inp();
    Try(1,1);
    sort(vt.begin(),vt.end());
    for(auto it1:vt){
        for(int x: it1){
            cout<<x<<" ";
        }
        cout<<"\n ";
    }
}