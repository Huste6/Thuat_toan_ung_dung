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
        adj[y].push_back({x,w});
    }
}
void prim(int s){
    taken[s]=true;//nap s vao cay khung
    priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> Q;
    for(auto it:adj[s]){
        int t=it.first;
        if(!taken(t)){
            Q.push({it.second,t});
        }
    }
    int d=0,dem=0;
    while(!Q.empty()){
        //lay canh ngan nhat
        pair<int,int> e=Q.top();Q.pop();
        int u=e.second,w=e.first;
        if(!taken(u)){
            ++dem;
            d+=w;
            taken[u]=true;
            for(auto it:adj[u]){
                int t=it.first;
                if(!taken(t)){
                    Q.push({it.second,t});
                }
            }
        }
    }
    if(dem==n-1) cout<<d<<endl;
    else cout<<"IMPOSIBLE";
}
int main(){
    nhap();
    prim(1);
}