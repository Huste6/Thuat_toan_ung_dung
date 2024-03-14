#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;cin>>n>>m;
    int a[n];
    for(int &x:a) cin>>x;
    ll sum=0;int l=0,res=1e6+2;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum>=m){
            res=min(res,i-l+1);
            sum-=a[l++];
        }
    }
    cout<<res<<endl;
}