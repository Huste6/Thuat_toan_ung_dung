#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    string s;cin>>s;
    set<char> se;
    for(char x:s) se.insert(x);
    map<char,int> mp;int cnt=0;
    int ans=1e9+1;int l=0;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        if(mp[s[i]]==1) ++cnt;
        while(cnt >= se.size()){
            ans=min(ans,i-l+1);
            mp[s[l]]--;
            if(mp[s[l]]==0) cnt--;
            l++;
        }
    }
    cout<<ans;
}