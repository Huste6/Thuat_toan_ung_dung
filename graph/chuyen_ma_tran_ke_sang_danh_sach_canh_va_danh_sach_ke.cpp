#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];
vector<int> ke[1001];
vector<pair<int,int>> canh;

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                canh.push_back({i,j});
                ke[i].push_back(j);
            }
        }
    }
    cout<<"danh sach ke"<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<" : ";
        sort(ke[i].begin(),ke[i].end());
        for(int it:ke[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    cout<<"danh sach canh"<<endl;
    sort(begin(canh),end(canh));
    for(auto it:canh){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}