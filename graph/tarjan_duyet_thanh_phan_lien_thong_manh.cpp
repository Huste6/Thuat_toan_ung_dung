#include<bits/stdc++.h>
using namespace std;

int n, m, timer = 0;
vector<int> adj[1005];
int disc[1005], low[1005];
bool visited[1005],in_stack[1005];stack<int> st;
int tpltmanh=0;

void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    visited[u]=true;in_stack[u]=true;
    disc[u]=low[u]=++timer;
    st.push(u);
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],disc[v]);
        }
    }
    if(low[u] == disc[u]){
        ++tpltmanh;
        //day la cach day cac phan tu dung tren gia tri u trong stack
        while(st.top()!=u){
            cout<<st.top()<<" ";
            in_stack[st.top()]=false;
            st.pop();
        }
        cout<<st.top()<<endl;
        in_stack[st.top()]=false;
        st.pop();
    }
}
int main(){
    nhap();
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    cout<<tpltmanh<<endl;
}
/*
7 8
1 2
2 3
3 1
3 4
4 5
5 6
6 7
7 5
*/