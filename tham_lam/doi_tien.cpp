#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD=1e9+7;

int main(){
    int n;cin>>n;
    int a[]={1000 , 500 , 200 , 100 , 50 , 20 , 10 , 5 , 2 , 1};
    int ans=0;
    for(int i=0;i<10;i++){
        ans+=n/a[i];
        n%=a[i];
        cout<<ans<<" to "<<a[i]<<endl;
    }
    cout<<ans;
}