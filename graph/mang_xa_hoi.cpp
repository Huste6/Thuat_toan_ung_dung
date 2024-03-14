#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[1001];
bool visited[1001];
vector<int> tplt;

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}

void dfs(int u){
    visited[u]=true;
    tplt.push_back(u);
    for(int x:ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main(){
    inp();
    bool ok=false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            tplt.clear();
            dfs(i);
            for(int x:tplt){
                if(ke[x].size() != tplt.size()-1){
                    cout<<"NO";return 0;
                }
            }
        }
    }
    cout<<"YES";
    return 0;
}m