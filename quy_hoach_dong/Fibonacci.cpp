#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
const int maxn=1e6;
//c1: dung ma tran nhu trong bai chia de tri
//c2:
ll f[maxn];
void fibo(){
    f[0]=0;f[1]=1;
    for(int i=2;i<=1e6;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
}
int main(){
    fibo();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<f[n]<<endl;
    }
}
