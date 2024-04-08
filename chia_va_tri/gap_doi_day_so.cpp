#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gapdoi(ll n,ll k){
    if(k%2==1) return 1;
    ll x=pow(2,n-1);
    if(x==k) return n;
    else if(k>x) return gapdoi(n-1,k-x);
    else return gapdoi(n-1,k);
}
int main(){
    ll n,k;cin>>n>>k;
    cout<<gapdoi(n,k);
}