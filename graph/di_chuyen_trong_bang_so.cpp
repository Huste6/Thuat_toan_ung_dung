#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[1001][1001];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};

void nhap(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
}
void dijkstra(int n,int m){
    vector< vector<ll> > d(n+1,vector<ll>(m+1,1e9));
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> Q;
    Q.push({a[1][1],make_pair(1,1)});
    d[1][1]=a[1][1];
    while(!Q.empty()){
        pair<int,pair<int,int>> top=Q.top();Q.pop();
        if(d[top.second.first][top.second.second] < top.first)  continue;
        for(int i=0;i<4;i++){
            int i1=dx[i]+top.second.first;
            int j1=dy[i]+top.second.second;
            if(i1<1 || i1>n || j1<1 || j1>m) continue;
            if(d[i1][j1] > top.first+a[i1][j1]){
                d[i1][j1]=top.first+a[i1][j1];
                Q.push({d[i1][j1],make_pair(i1,j1)});
            }
        }
    }
    cout<<d[n][m];
}
int main(){
    nhap();
    dijkstra(n,m);
}