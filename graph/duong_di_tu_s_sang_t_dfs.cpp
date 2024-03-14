#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int n,m,s,t;
int parent[1001];

void dfs(int u){
    visited[u]=true;
    for(int x:ke[u]){
        if(!visited[x]){
            parent[x]=u;
            dfs(x);
        }
    }
}

void inp(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++) sort(ke[i].begin(),ke[i].end());
    memset(visited,false,sizeof(visited));
}
int main(){
    inp();
    dfs(s);
    if(!visited[t]) cout<<-1;
    else{
        vector<int> path;
        int curr = t; 
        while(curr!=s){
            path.push_back(curr);
            curr=parent[curr];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int x:path){
            cout<<x<<" ";
        }
    }
    return 0;
}
