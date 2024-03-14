#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;cin>>n>>m;
    int a[n];
    for(int &x:a) cin>>x;
    int j=0;ll sum=0,cnt_qua=0,res=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        cnt_qua++;
        while(sum > m){
            sum-=a[j++];
            cnt_qua--;
        }
        res=max(res,cnt_qua);
    }
    cout<<res<<endl;
}