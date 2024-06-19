#include<bits/stdc++.h>
using namespace std;
const int N=10005;
vector<int> T[N];
int match[N],visited[N];
bool dfs(int u){
    for(int v:T[u]){
        if(!visited[v]){
            visited[v]=true;
            if(match[v]==-1 || dfs(match[v])){
                match[v]=u;
                return true;
            }
        }
    }
    return false;   
}
void max_matching(int n,int m){
    int cnt=0;
    memset(match,-1,sizeof(match));
    for(int u=1;u<=n;u++){
        memset(visited,false,sizeof(visited));
        if(dfs(u)){
            cnt++;
        }
    }
    cout<<cnt;
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int t;cin>>t;
            T[i].push_back(t);
        }
    }
    max_matching(n,m);
    return 0;
}