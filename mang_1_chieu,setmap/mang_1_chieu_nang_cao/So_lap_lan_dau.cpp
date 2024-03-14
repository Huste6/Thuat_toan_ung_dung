#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int MAXn=1e6+1;
int ans[MAXn];
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a){
        cin>>x;
        ans[x]++;
        if(ans[x]>=2){
            cout<<x;
            return 0;
        }
    }
    cout<<-1;
}