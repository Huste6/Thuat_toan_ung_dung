#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXn=1e5+2;
int main(){
    int n;cin>>n;int so;cin>>so;
    int a[n];
    for(int &x:a) cin>>x;
    int ck=0;int d,c;
    for(int i=0;i<n;i++){
        if(ck==0 && a[i] == so){
            d=i+1;
            ck=1;
        }
        else if(ck==1 && a[i] == so){
            c=i+1;
        }
    }
    if(ck) cout<<d<<' '<<c<<endl;
    else cout<< -1 <<' '<< -1<<endl;
    return 0;
}