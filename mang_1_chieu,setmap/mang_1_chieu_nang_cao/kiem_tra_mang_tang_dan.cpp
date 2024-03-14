#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    bool check=true;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            check=false;
            break;
        }
    }
    if(check) cout<<"YES";
    else cout<<"NO";
}