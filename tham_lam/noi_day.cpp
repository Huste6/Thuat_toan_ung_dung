#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD=1e9+7;
//push pop top size empty
//priority_queue<int> q;//max_heap
//priority_queue<int,vector<int>,greater<int>> q;//min_heap
//co the dung multiset
int main(){
    priority_queue<ll,vector<ll>,greater<ll>> q;//min_heap
    int n;cin>>n;ll ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        q.push(x);
    }
    while(q.size()>1){
        ll x=q.top();
        q.pop();
        ll y=q.top();
        q.pop();
        ans+=x+y;
        q.push(x+y);
    }
    cout<<ans;
}