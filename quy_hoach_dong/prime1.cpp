#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
const int maxn=1e6;
int f[maxn];
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

void prime1(){
    f[0]=0;
    for(int i=1;i<=1e6;i++){
        if(t[i]==true){
            f[i]=f[i-1];
        }else f[i]=f[i-1]+1;
    }
}
int main(){
    memset(t,false,sizeof(t));
    sang();
    prime1();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}