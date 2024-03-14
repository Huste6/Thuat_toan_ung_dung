#include<bits/stdc++.h>
using namespace std;

int n,m;vector<int> ke[10001];
int color[10001];
int parent[10001];
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(color,0,sizeof(color)); 
}
//mau 1: do
//mau 2: xanh
bool dfs(int u,int par){
    color[u]=3-color[par];
    for(int v:ke[u]){
        if(color[v]==0){
            if(!dfs(v,u)) return false;
        }else if(color[v]==color[u]) return false; 
    }
    return true;
}
int main(){
    inp();
    bool ok=true;
    color[0]=2;
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            if(!dfs(i,0)) ok=false;
        }
    }
    cout<<ok<<endl;
}