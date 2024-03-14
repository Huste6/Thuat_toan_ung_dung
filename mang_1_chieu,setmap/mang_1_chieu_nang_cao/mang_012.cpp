#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXn=1e5+2;
int main(){
    int n;cin>>n;
    int a[n];
    int b[4];memset(b,0,sizeof(b));
    for(int &x:a){
        cin>>x;
        b[x]++;
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<b[i];j++){
            cout<<i<<' ';
        }
    }
    return 0;
}