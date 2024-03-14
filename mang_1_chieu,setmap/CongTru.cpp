#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    int b[n-1];
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    int sum=a[0];
    for(int i=0;i<n-1;i++){
        if(b[i]==1) sum+=a[i+1];
        if(b[i]==2) sum-=a[i+1];
    }
    cout<<sum;
}