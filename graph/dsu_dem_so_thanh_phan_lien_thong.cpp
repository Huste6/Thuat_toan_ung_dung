#include<bits/stdc++.h>
using namespace std;
int n,m;int parent[1001],sz[1001];

int find(int u){
    while(u!=parent[u]){
        u=parent[u];
    }
    return u;
}

bool union_1(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return false;
    else{
        if(u<v) parent[v]=u;
        else parent[u]=v;
        return true;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        union_1(x,y);
    }
    int dem=0;
    for(int i=1;i<=n;i++){
        if(i==parent[i]) ++dem;
    }
    cout<<dem<<endl;
}