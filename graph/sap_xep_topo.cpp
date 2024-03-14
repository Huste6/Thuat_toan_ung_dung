#include<bits/stdc++.h>
using namespace std;

//topological sort: do thi co huong
//dfs
//bfs (kahn) : thuat toan xoa dan dinh (dem ban bac vao)

int n,m;vector<int> ke[10001];
bool visited[10001];
vector<int> topo;
int indegree[10001];

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        indegree[y]++;
    }
    memset(visited,false,sizeof(visited)); 
}

void dfs(int u){
    visited[u]=true;
    for(int v:ke[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    topo.push_back(u);//u da duoc duyet xong
}
//xoa dan dinh
void kahn(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        cout<<u<<" ";
        for(int v:ke[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
}

int main(){
    inp();
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(begin(topo),end(topo));
    for(int x:topo) cout<<x<<" ";
    cout<<endl;
    kahn();
}