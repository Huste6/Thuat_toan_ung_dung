#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int a[n];
        for(int &x:a) cin>>x;
        int res=0;
        for(int x:a){
            if(x<=k) res++;
        }
        ll cnt_nho_hon_k=0;
        for(int i=0;i<res;i++){
            if(a[i]<k) cnt_nho_hon_k++;
        }
        ll ans=cnt_nho_hon_k;
        for(int i=res;i<n;i++){
            if(a[i-res]<=k) cnt_nho_hon_k--;
            if(a[i]<=k) cnt_nho_hon_k++;
            if(cnt_nho_hon_k>ans){
                ans=cnt_nho_hon_k;
            }
        }
        cout<<abs(ans-res)<<endl;
    }
}