#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXn=1e6+2;
int main(){
    int n,d;cin>>n>>d;
    int a[n];int cnt=0;
    for(int &x:a) cin>>x;
    for(int i=1;i<n;i++){
        while(a[i-1] >= a[i]){
            a[i]+=d;
            cnt+=1;
        }
    }
    cout<<cnt;
    return 0;
}