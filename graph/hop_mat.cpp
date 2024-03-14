#include<bits/stdc++.h>
using namespace std;

int k,n,m;
vector<int> pos;
bool visited[1001];
vector<int> ke[1001];
int cnt[1001];

void inp(){
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        int x;cin>>x;
        pos.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
    }
    memset(visited,false,sizeof(visited));
}

void dfs(int u){
    cnt[u]++;
    visited[u]=true;
    for(int x:ke[u]){
        if(!visited[x]){
            dfs(x);
        }
    }
}
int main(){
    inp();
    for(int x:pos){
        memset(visited,false,sizeof(visited));
        dfs(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
            ans++;
        }
    }
    cout<<ans<<endl;
}