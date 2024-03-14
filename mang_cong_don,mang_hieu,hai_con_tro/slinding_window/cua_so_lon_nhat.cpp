#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int q;cin>>q;
    while(q--){
        int n,k;cin>>n>>k;
        int a[1001];
        for(int &x:a) cin>>x;
        long long sum=0;
        for(int i=0;i<k;i++) sum+=a[i];
        ll res=sum,index=0;
        for(int i=k;i<n;i++){
            sum=sum-a[i-k]+a[i];
            if(sum>res){
                index=i-k+1;
                res=sum;
            }
        }
        cout<<res<<endl;
        for(int i=0;i<k;i++){
            cout<<a[index+i]<<' ';
        }
        cout<<endl;
    }    
}