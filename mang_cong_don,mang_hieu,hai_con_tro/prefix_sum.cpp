//pre[i]=a[0]+...+a[i]
//pre[i-1]+a[i]=pre[i]
//pre[r]-pre[l-1] tong cac phan tu tu l den r
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    int pre[n];//ll
    for(int i=0;i<n;i++){
        if(i==0) pre[i]=a[i];
        else pre[i]=pre[i-1]+a[i];
    }
    int q;cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        if(l==0) cout<<pre[r];
        else cout<<pre[r]-pre[l-1];
    }
    return 0;
} 
