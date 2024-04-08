#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=1;
    }
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1]) b[i]=b[i-1]+1;
        else if(a[i]<=a[i-1]) b[i]=1;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i] > a[i+1] && (b[i]==1 || b[i]==b[i+1])) b[i]=b[i+1]+1;
    }
    for(int i=0;i<n;i++) cout<<b[i]<<" ";
}