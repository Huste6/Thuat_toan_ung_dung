#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,s;cin>>n>>s;
    int a[n];
    for(int &x:a) cin>>x;
    int l=0,res=0;ll sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum >= s){
            sum-=a[l++];
        }
        res+=r-l+1;
    }
    cout<<res<<endl;
}