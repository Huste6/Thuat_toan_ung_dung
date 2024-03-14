#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[200002]={0};
ll d[200002]={0};
ll f[200002]={0};
int main(){
    int n,k,q;cin>>n>>k>>q;
    while(n--){
        int l,r;cin>>l>>r;
        --l;--r;
        d[l]+=1;
        d[r+1]-=1;
    }
    f[0]=d[0];
    for(int i=1;i<200000;i++){
        f[i]=d[i]+f[i-1];
    }
    while(q--){
        int l,r;cin>>l>>r;
        --l;--r;
        int cnt=0;
        for(int i=l;i<=r;i++){
            if(f[i]>=k) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}