#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
const int maxm=1e6+1;
int n,m;
bool visited[maxn];
vector<int> ke[maxn];
vector<int> ke_ngc[maxn];
int tpltmanh=0;
std::stack<int> st;
void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke_ngc[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}
void dfs1(int u){
    visited[u]=true;
    for(int x: ke[u]){
        if(!visited[x]){
            dfs1(x);
        }
    }
    st.push(u);
}
void dfs2(int u){
    visited[u]=true;
    for(int x:ke_ngc[u]){
        if(!visited[x]){
            dfs2(x);
        }
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    memset(visited,false,sizeof(visited));
    while(!st.empty()){
        int x=st.top();st.pop();
        if(!visited[x]){
            tpltmanh++;
            dfs2(x);
        }
    }
}
int main(){
    inp();
    solve();
    cout<<tpltmanh;
}
