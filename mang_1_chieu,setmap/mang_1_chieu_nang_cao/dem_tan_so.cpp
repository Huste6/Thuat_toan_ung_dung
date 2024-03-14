#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    map<int,int> mp;
    for(int x:a){
        mp[x]++;
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(mp[a[i]] != 0){
            cout<<a[i]<<' '<<mp[a[i]]<<endl;
            mp[a[i]]=0;
        }
    }
}