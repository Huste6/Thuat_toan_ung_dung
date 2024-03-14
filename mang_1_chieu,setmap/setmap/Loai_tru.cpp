#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int a[n];set<int> b,c;
    for(int &x:a) cin>>x;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b.insert(x);
    }
    for(int i=0;i<n;i++){
        if(b.count(a[i])==0) c.insert(a[i]);
    }
    for(auto it:c) cout<<it<<' ';
}