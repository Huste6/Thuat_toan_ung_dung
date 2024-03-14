#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXn=1e5+2;
int main(){
    int n;cin>>n;
    int a[n],b[n];
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    sort(a,a+n);
    sort( b,b+n, greater<int>() );
    int k1=0,k2=0;
    for(int i=0;i<2*n;i++){
        if(i%2==0){
            cout<<a[k1++]<<' ';
        }else cout<<b[k2++]<<' ';
    }
    return 0;
}