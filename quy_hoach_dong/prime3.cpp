#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
const int maxn=1e6;
ll f[maxn];
bool t[maxn];

void sang(){
    t[0]=t[1]=true;
    for(int i=2;i<=sqrt(maxn);i++){
        if(t[i]==false){
            for(int j=i*i;j<=maxn;j+=i){
                t[j]=true;
            }
        }
    }
}

void prime3(){
    f[0]=0;
    for(int i=1;i<=1e6;i++){
        if(t[i]==true) f[i]=f[i-1];
        else{
            if(f[i-1]==0) f[i]=i;
            else f[i]=f[i-1]*i;
            f[i]%=mod;
        }
    }
}
int main(){
    memset(t,false,sizeof(t));
    sang();
    prime3();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}