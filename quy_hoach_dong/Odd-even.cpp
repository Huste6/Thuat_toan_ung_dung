#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
//tao mang F luu le-chan
int main(){
    int n;cin>>n;
    int a[n+1];map<int,int> mp;
    int t=0;int F[n+1]={0};ll cnt=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2==1){
            t++;
        }
        else t--;
        F[i]=t;
        cnt+=mp[F[i]];
        mp[F[i]]++;
    }
    cout<<cnt;
}