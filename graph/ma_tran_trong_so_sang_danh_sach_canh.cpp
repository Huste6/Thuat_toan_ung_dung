#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1001][1001];
vector<vector<int>> canh;
int n;
bool visited[1001][1001];
void inp(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]!=0 && !visited[i][j] && !visited[j][i]){
                canh.push_back({i,j,a[i][j]});
                visited[i][j]=true;
                visited[j][i]=true;
            }
        }
    }
    sort(begin(canh),end(canh));
    for(auto it:canh){
        for(int i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    inp();
}