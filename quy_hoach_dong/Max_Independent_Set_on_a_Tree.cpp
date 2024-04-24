#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=100001;
vector<ll> adj[maxn+1];
unordered_map<ll,ll> w,dp_include,dp_exclude;
void dfs(ll node,ll parent){
    dp_include[node]=w[node];
    dp_exclude[node]=0;
    for(int child : adj[node]){
        if(child==parent) continue;
        dfs(child,node);
        dp_include[node]+=dp_exclude[child];
        dp_exclude[node]+=max(dp_include[child],dp_exclude[child]);
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        ll w1;cin>>w1;
        w[i]=w1;
    }
    for(int i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(dp_include[1],dp_exclude[1])<<endl;
    return 0;
}
