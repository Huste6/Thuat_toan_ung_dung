#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+1;
ll Mod=1e9+7;
ll gt[maxn];
void giaithua(){
    gt[0]=gt[1]=1;
    for(int i=2;i<=1e6;i++){
        gt[i]=(gt[i-1]*i)%Mod;
    }
}
int main(){
    giaithua();
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<gt[n]<<endl;
    }
}