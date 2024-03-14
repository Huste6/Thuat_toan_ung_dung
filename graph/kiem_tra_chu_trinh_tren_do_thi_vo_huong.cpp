#include<bits/stdc++.h>
using namespace std;

//check canh nguoc
int n,m;vector<int> ke[10001];
bool visited[10001];
int parent[10001];

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited,false,sizeof(visited)); 
}
//do thi vo huong
bool dfs(int u,int par){
    visited[u]=true;
    for(int v:ke[u]){
        if(!visited[v]){
            if(dfs(v,u)) return true;
        }//dinh v da duoc tham nhung u khong phai la cha truc tiep cua v
        else if(v != par){
            return true; 
        }
    }
    return false; 
}

bool bfs(int u){
    queue<int> q;
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int x:ke[v]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
                parent[x]=v;
            }else if(x != parent[v]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    inp();
    bool ok=false;
    /*
    for(int i=1;i<=n;i++){
        if(!visited[i] && dfs(i,0)){
            ok=true;
            break;
        }
    }*/
    for(int i=1;i<=n;i++){
        if(!visited[i] && bfs(i)){
            ok=true;
            break;
        }
    }
    cout<<ok<<endl;
}