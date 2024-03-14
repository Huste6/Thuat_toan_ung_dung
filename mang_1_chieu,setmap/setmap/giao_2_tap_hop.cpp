#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int a[n],b[m];
    for(int &x:a) cin>>x;
    set<int> seB;
    for(int &x:b){
        cin>>x;
        seB.insert(x);
    }
    for(int i=0;i<n;i++){
        if(seB.count(a[i])!=0){
            cout<<a[i]<<" ";
            seB.erase(a[i]);
        }
    }
}