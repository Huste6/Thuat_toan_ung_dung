#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    string s;cin>>s;
    int x,y;cin>>x>>y;
    map<char,int> mp;
    int l=0,ans=0;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        while(mp['2']>x || mp['8']>y){
            mp[s[l++]]--;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}