#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];

    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(b[i]!=a[i] && b[i] != a[n-i-1]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}