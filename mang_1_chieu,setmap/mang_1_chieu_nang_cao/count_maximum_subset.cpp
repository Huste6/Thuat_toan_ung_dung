#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e6+2;
const int MAXn=1e9+7;
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    multiset<int> se;
    sort(a,a+n);int ans=0;
    int l=0;
    for(int i=0;i<n;i++){
        se.insert(a[i]);
        while(*se.rbegin()-*se.begin()>k){
            se.erase(a[l++]);
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}