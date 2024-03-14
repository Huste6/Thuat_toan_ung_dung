#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;cin>>n>>k;
    int a[n],ans=0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(mp.find(k+x)!=mp.end()){
            ans=max(ans,i-mp[x+k]);
        }
        if(mp.find(x-k)!=mp.end()){
            ans=max(ans,i-mp[x-k]);
        }
        if(mp.find(x)==mp.end()){
            mp[x]=i;
        }
    }
    if(ans!=0) cout<<ans;
    else cout<<-1;
}