#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    multiset<int> se;
    int l=0;int ans=0;
    for(int i=0;i<n;i++){
        se.insert(a[i]);
        while((*se.rbegin()- *se.begin())>k){
            se.erase(se.find(a[l++]));
        }
        ans+=i-l+1;
    }
    cout<<ans;
    return 0;
}