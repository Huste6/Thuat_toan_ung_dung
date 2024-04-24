#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[1001];
bool visited[1001];
vector<pair<int,int>> edge;
void nhap(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        edge.push_back({x,y});
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}
void dfs(int u,int s,int t){
    visited[u]=true;
    for(int v:adj[u]){
        if((u==s && v==t) || (u==t && v==s)) continue;
        if(!visited[v]){
            dfs(v,s,t);
        }
    }
}
int tlpt(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cnt++;
            dfs(i);
        }
    }
}
void canh_cau(){
    int cc=tlpt();
    for(pair<int,int> e:edge){
        int s=e.first,t=e.second;
        memset(visited,false,sizeof(visited));
        if(cc<tlpt()){
            cout<<s<<" "<<t<<endl;
        }
    }
}
int main(){
    nhap();
    canh_cau();
    return 0;
}