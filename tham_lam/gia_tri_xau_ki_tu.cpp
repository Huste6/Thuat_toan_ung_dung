#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;
        map<char,int> mp;
        for(char x:s){
            mp[x]++;
        }
        priority_queue<int> q;
        for(auto it:mp){
            q.push(it.second);
        }
        while(!q.empty() && n-- && q.top()!=0){
            int tmp=q.top();
            q.pop();
            tmp--;
            if(tmp!=0) q.push(tmp);
        }
        ll res=0;
        while(!q.empty()){
            res+=q.top()*q.top();
            q.pop();
        }
        cout<<res;
    }
}