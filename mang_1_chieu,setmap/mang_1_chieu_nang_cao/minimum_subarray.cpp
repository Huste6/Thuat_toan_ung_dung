#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e6+2;
const int MAXn=1e9+7;
/*
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    int l=0,sum=0,ans=MOD;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum >=  k){
            if(sum==k){
                ans=min(ans,i-l+1);
            }
            sum-=a[l++];
        }
    }
    if(ans==MOD) cout<<-1;
    else cout<<ans;
}*/
/*
int main(){
    int n,k;cin>>n>>k;
    int a[n];ll sum=0;
    for(int &x:a) cin>>x;
    map<ll,int> mp;
    mp[0]=-1;int index=-1,res=MOD;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(mp.count(sum-k)){
            //res=min(res,i-mp[sum-k]);
            if(res > i-mp[sum-k]){
                res=min(res,i-mp[sum-k]);
                index=mp[sum-k]+1;
            }
        }
        mp[sum]=i;
    }
    //cout<<res;
    if(index!=-1){
        for(int i=index;i<=index+res-1;i++){
            cout<<a[i]<<" ";
        }
    }else cout<<"NOT FOUND";
}*/
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    ll sum=0;
    map<ll,int> mp;
    mp[0]=-1;int res=0,index=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(mp.count(sum-k)){
            if(res<i-mp[sum-k]){
                res=i-mp[sum-k];
                index=mp[sum-k]+1;
            }
        }
        mp[sum]=i;
    }
    if(index!=-1){
        for(int i=index;i<=index+res-1;i++){
            cout<<a[i]<<' ';
        }
    }else cout<<"NOT FOUND";
    return 0;
}