#include<bits/stdc++.h>
using namespace std;
using ll=long long;
typedef struct Node{
    int x,y,z;
}Node;
int main(){
    int n,m,k;cin>>n>>m>>k;
    int a[n];
    for(int &x:a) cin>>x;
    ll d[n+2];
    d[0]=a[0];
    for(int i=1;i<n;i++){
        d[i]=a[i]-a[i-1];
    }
    vector<Node> vt;vt.resize(m+2,0);
    for(int i=0;i<m;i++){
        cin>>vt[i].x>>vt[i].y>>vt[i].z;
    }
    while(k--){
        int x,y;cin>>x>>y;
        --x;--y;
        for(int j=x;j<=y;j++){
            int l1=vt[j].x;
            int r1=vt[j].y;
            int k1=vt[j].z;
            d[l1]+=k1;
            d[r1+1]-=k1;
        }
    }
    ll f[n+2];
    f[0]=d[0];
    for(int i=1;i<n;i++){
        f[i]=d[i]+f[i-1];
    }
    for(int i=0;i<n;i++){
        cout<<f[i]<<" ";
    }
    return 0;
}