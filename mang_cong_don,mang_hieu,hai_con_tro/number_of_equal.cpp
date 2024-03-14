#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int a[n],b[m];
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    int i=0,j=0;long long res=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            ++i;continue;
        }else if(a[i]>b[j]){
            ++j;continue;
        }
        int dem1=0,dem2=0;
        while(a[i]==b[j]){
            dem1++; ++i;
        }
        while(a[i-1]==b[j]){
            dem2++; ++j;
        }
        res+=1ll*dem1*dem2;
    }
    cout<<res<<endl;
}