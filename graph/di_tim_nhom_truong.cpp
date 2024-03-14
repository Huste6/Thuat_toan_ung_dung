#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001];
vector<int> ke[1001];
vector<int> tplt;

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++) sort(ke[i].begin(),ke[i].end());
}

void dfs(int u){
    tplt.push_back(u);
    visited[u]=true;
    for(int v:ke[u]){
        if(!visited[v]) dfs(v);
    }
}

int main(){
    inp();
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            tplt.clear();
            dfs(i);
            int res=i,max_val=0;
            sort(begin(tplt),end(tplt));
            for(int x:tplt){
                if(ke[x].size() > max_val){
                    max_val=ke[x].size();
                    res=x;                
                }
            }
            ans.push_back();
        }
    }
    sort(begin(ans),end(ans));
    for(int x:ans){
        cout<<x<<" ";
    }
}