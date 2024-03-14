#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> ke[10001];
vector<int> t_ke[10001];
bool visited[10001];
stack<int> st;
int tpltmanh=0;

void inp(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
    memset(visited,false,sizeof(visited));
}

void dfs1(int u){
    visited[u]=true;
    for(int v:ke[u]){
        if(!visited[v]) dfs1(v);
    }
    st.push(u);//duyet xong u
}

void dfs2(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int v:t_ke[u]){
        if(!visited[v]) dfs2(v);
    }
}

void kosaraju(){
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    memset(visited,false,sizeof(visited));
    while(!st.empty()){
        int top=st.top();st.pop();
        if(!visited[top]){
            ++tpltmanh;
            dfs2(top);
            cout<<endl;
        }
    }
    cout<<tpltmanh<<endl;
}
int main(){
    inp();
    kosaraju();
    return 0;
}