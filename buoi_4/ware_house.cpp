#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,T,D;
    cin>>n>>T>>D;
    vector<int> a(n+1),t(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>t[j];
    ll f[n+1][T+1];
    //x[i] x[i+1] khoang cach ko qua D, co tong thoi gian khong qua T
    memset(f,0,sizeof(f));    
    f[1][t[1]]=a[1];
    for(int i=2;i<=n;i++){
        for(int j=max(1,i-D);j<=i-1;j++){
            for(int k=1;k<=T;k++){
                if(k>=t[i]) f[i][k]=max(f[i][k], f[j][k-t[i]]+a[i]);
            }
        }
    }
    //i la xe tiep theo chay tu 2 -> n
    //j la xe truoc day 
    //k la thoi gian 
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=T;j++){
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
}