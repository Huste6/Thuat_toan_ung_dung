#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+2;
int n,m,w;
vector<pair<int,int>> adj[maxn];
bool visited[maxn];
void inp(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y,z;cin>>x>>y>>z;
        adj[x].push_back({y,z}); 
        adj[y].push_back({x,z}); 
    }
    memset(visited,false,sizeof(visited));
}
pair<int,int> bfs(int s,int dis){
    int last_node=0;
    vector<int> ans(n+1, 0); 
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()){
        int t=q.front();q.pop();
        for(pair<int,int> it : adj[t]){
            if(!visited[it.first]){
                visited[it.first]=true;
                ans[it.first]=ans[t]+it.second;
                if(ans[it.first] > dis){ 
                    dis=ans[it.first];
                    last_node=it.first;
                }
                q.push(it.first); 
            }
        }
    }
    return make_pair(last_node,dis);
}
int main(){
    inp();
    pair<int,int> t1,t2;
    t1=bfs(1,0);
    memset(visited,false,sizeof(visited));
    t2=bfs(t1.first,0);
    cout<<t2.second; 
    return 0;
}
