#include<bits/stdc++.h>
using namespace std;
int n;int parent[1001],sz[1001];

void ktao(){
    cin>>n;
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

//tim dai dien cho dinh u
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
//toi uu nen duong
int find_1(int u){
    if(u==parent[u]){
        return u;
    }
    return parent[u]=find(parent[u]);
}
//toi uu gop
bool union_2(int u,int v){
    u=find_1(u);
    v=find_1(v);
    if(u==v) return false;
    if(sz[u]<sz[v]){
        swap(u,v);
    }
    sz[u]+=sz[v];
    parent[v]=u;
    return true;
}
int main(){
    ktao();
    cout<<union_1(6,7)<<endl;
    cout<<union_1(5,6)<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<parent[i]<<endl;
    }
}