#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    cout<<a[0]<<" ";
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            cout<<a[i]<<' ';
            max=a[i];
        }
    }
}