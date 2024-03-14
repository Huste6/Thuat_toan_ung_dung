#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;cin>>n>>m;

    int a[n];
    for(int &x:a) cin>>x;
    ll sum=0;int ans=1e9+1,l=0,index=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum>=m){
            if(ans > i-l+1){
                ans=i-l+1;
                index=l;
            }
            sum-=a[l++];
        }
    }
    for(int i=index;i<=index+ans-1;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}