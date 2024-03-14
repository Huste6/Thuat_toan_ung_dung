#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        int l=i+1,r=n-1;
        while(l<r){
            int sum=a[l]+a[i]+a[r];
            if(sum==k){
                cout<<"YES"; return 0;
            }else if(sum>k){
                --r;
            }else ++l;
        }
    }
    cout<<"NO";return 0;
}