#include<bits/stdc++.h>
using namespace std;

vector<int> ke[10001];

int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);//neu do thi co huong thi ko them vao
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" : ";
        sort(ke[i].begin(),ke[i].end());
        for(int x:ke[i]){
            cout<<x<<' ';
        }
        cout<<endl;
    }
}