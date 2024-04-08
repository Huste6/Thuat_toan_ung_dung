#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
    int n;cin>>n;
    if(n==0){
        cout<<0;
        return;
    }
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int F[n+1];
    F[0]=0;
    for(int i=1;i<=n;i++) F[i]=F[i-1]+a[i];
    int min_curr=-1e9,max_sum=a[0];
    for(int i=1;i<=n;i++){
        min_curr=min(min_curr,F[i]);
        max_sum=max(max_sum,F[i]-min_curr);
    }
    cout<<max_sum;
}