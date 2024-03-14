#include<bits/stdc++.h>
using namespace std;
const int MOD=1e6+2;
using ll =long long;
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    int index=0,l=0,ans=-1;ll sum=0;
    map<ll,int> mp;
    mp[0]=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(mp.count(sum)){
            l=i-mp[sum];
            if(l>ans){
                index=mp[sum]+1;
                ans=l;
            }
        }else mp[sum]=i;
    }
    if(ans!=-1){
        for(int i=index;i<=index+ans-1;i++){
            cout<<a[i]<<' ';
        }
    }else cout<<"NOT FOUND";
}