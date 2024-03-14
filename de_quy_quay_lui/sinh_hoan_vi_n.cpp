#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int x[100],n,visited[100];
//visited[i]=1 thi da dung roi con =0 thi chua dung
void Try(int i){
    for(int j=1;j<=n;j++){
        if(visited[j]==0){
            x[i]=j;
            visited[j]=1;
            if(i==n){
                for(int i=1;i<=n;i++) cout<<x[i];
                cout<<endl;
            }else Try(i+1);
            visited[j]=0;
        }
    }
}
int main(){
    memset(visited,0,sizeof(visited));
    cin>>n;
    Try(1);
}