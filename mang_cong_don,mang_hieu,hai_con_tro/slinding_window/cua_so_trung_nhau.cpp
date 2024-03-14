#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool solve(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    set<int> s;
    for(int i=0;i<k;i++){
        if(s.count(a[i])!=0) return true;
        s.insert(a[i]);
    }
    for(int i=k;i<n;i++){
        s.erase(a[i-k]);
        if(s.count(a[i]!=0)) return true;
        s.insert(a[i]);
    }
    return false;
}
int main(){
    int t;cin>>t;
    while(t--){
        if(solve()) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}