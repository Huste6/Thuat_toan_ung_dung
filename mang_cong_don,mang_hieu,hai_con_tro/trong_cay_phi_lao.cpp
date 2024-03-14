#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,m;cin>>n>>m;
    int a[n];
    for(int &x:a) cin>>x;
    int cnt_1=0;
    for(int i=0;i<m;i++){
        if(a[i]==1) cnt_1++;
    }
    int res=cnt_1;
    for(int i=m;i<n;i++){
        if(a[i-m]==1) cnt_1--;
        if(a[i]==1) cnt_1++;
        res=max(res,cnt_1);
    }
    cout<<m-res;
}