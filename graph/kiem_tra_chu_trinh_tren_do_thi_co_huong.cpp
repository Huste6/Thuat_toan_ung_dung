#include<bits/stdc++.h>
using namespace std;

int n,m;vector<int> ke[10001];
int color[10001];
int in[10001];
//mau 0: chua duoc tham
//mau 1: dang duoc tham
//mau 2: da tham xong

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        in[y]++;
    }
    memset(color,0,sizeof(color)); 
}

bool dfs(int u){
    color[u]=1;
    for(int v:ke[u]){
        if(color[v]==0){
            if(dfs(v)) return true;
        }else if(color[v]==1){
            return true;
        }
    }
    color[u]=2;
    return false;
}
bool kahn(){
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int v=q.front;q.pop();
        cnt++;
        for(int x:ke[v]){
            --in[x];
            if(in[x]==0){
                q.push(x);
            }
        }
    }
    if(cnt==n) return false;
    else return true;
}
int main(){
    inp();
    bool ok=false;
    for(int i=1;i<=n;i++){
        if(!color[i] && dfs(i)){
            ok=true;
            break;
        }
    }
    //cout<<ok<<endl;
    cout<<kahn()<<endl;
}
/*
inp:
5 4
1 2
2 3
4 1
4 5
out: 0
*/