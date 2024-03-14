#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,s;cin>>n>>s;
    int a[n];
    for(int &x:a) cin>>x;
    ll sum=0;int res=1e6+2,l=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum>=s){
            res=min(res,i-l+1);
            sum-=a[l++];
        }
    }
    cout<<res;
}