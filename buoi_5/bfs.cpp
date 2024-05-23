#include <bits/stdc++.h>
using namespace std;
int n,m;
bool visited[10001];
vector<int> adj[10001];
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        sort(adj[i].begin(),adj[i].end());
    }
}
void bfs(int u){
    visited[u]=true;
    std::queue<int> q;
    q.push(u);
    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<" ";
        for(int x:adj[f]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
int main()
{
    inp();
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    return 0;
}