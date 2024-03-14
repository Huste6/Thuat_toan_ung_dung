#include<bits/stdc++.h>
using namespace std;

int n,m,timer=0;
vector<int> ke[10001];
bool visited[10001];
int disc[10001],low[10001];
void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        //ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++) sort(ke[i].begin(),ke[i].end());
    memset(visited,false,sizeof(visited));
}
void dfs(int u){
    disc[u]=low[u]=++timer;
    visited[u]=true;
    for(int v:ke[u]){
        if(!visited[v]){
            dfs(v);
            low[u]=min(low[v],low[u]);
        }else{
            low[u]=min(low[u],disc[v]);
        }
    }
}
int main(){
    nhap();
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<disc[i]<<" "<<low[i]<<endl;
    }
    return 0;
}
/*
inp:
11 14
1 2
2 3
3 1
3 4
4 6
6 7
6 9
7 9
9 4
7 10
6 5
5 8
8 11
11 5
out:
1 1 1
2 2 1
3 3 1
4 4 4
5 6 6
6 5 4
7 9 4
8 7 6
9 10 4
10 11 11
11 8 6
*/