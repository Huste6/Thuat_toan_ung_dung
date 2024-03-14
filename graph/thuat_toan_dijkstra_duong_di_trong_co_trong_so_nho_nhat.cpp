#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m;
bool taken[1001];
vector<pair<int,int>> adj[1001];

void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
        //adj[y].push_back({x,w});
    }
}
void dijkstra(int s){
    vector<int> d(n+1,1e9);
    d[s]=0;
    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,s});
    while(!Q.empty()){
        //chon dinh u co duong di ngan nhat
        pair<int,int> top=Q.top();Q.pop();
        int u=top.second,kc=top.first;
        if(kc > d[u]) continue;
        for(auto it:adj[u]){
            int v=it.first,w=it.second;
            //neu ma khoang cach tu s sang v lon hon khoang cach tu s sang u roi sang v
            if(d[v] > d[u] + w){
                d[v]=d[u]+w;
                Q.push({d[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<d[i]<<' ';
    }
}
int main(){
    nhap();
    dijkstra(1);
}