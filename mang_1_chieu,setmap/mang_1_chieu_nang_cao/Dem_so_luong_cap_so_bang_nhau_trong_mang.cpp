#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD=1e9+7;
const int MAXn=1e6+1;
int ans[MAXn];
int main(){
    int n;cin>>n;
    int a[n];
    int Max=0,Min=MOD;
    for(int &x:a){
        cin>>x;
        ans[x]++;
        Max=max(Max,x);Min=min(Min,x);
    }
    ll cnt=0;
    for(int i=Min;i<=Max;i++){
        if(ans[i]!=0){
            cnt+=1ll*(ans[i]-1)*(ans[i])/2;
        }
    }
    cout<<cnt<<endl;
    return 0;
}