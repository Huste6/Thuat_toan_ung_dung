#include<bits/stdc++.h>
using namespace std;

int n,m;
bool visited[1001];
vector<int> ke[1001];

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();q.pop();
        for(int x:ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    inp();
    vector<int> res;
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            ++ans;
            res.push_back(i);
            bfs(i);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<res.size()-1;i++){
        cout<<res[i]<<" "<<res[i+1]<<endl;
    }
    return 0;
}