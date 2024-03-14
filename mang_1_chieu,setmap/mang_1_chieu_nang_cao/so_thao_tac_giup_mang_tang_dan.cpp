#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXn=1e6+2;
int main(){
    int n;cin>>n;
    int a[n];for(int &x:a) cin>>x;int cnt=0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]) cnt+=a[i-1]+1-a[i];
    }

    cout<<cnt;
}