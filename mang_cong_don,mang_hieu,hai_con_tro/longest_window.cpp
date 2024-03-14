#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    string s;cin>>s;
    map<char,int> mp;int cnt=0,l=0;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
        while(mp[s[i]]>1){
            mp[s[l]]--;
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}