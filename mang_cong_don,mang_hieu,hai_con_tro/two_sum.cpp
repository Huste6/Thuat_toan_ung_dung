#include<bits/stdc++.h>
using namespace std;
//c2
vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++){
        int c=target-nums[i];
        if(mp.count(c)!=mp.end()){
            return {mp[c],i};
        }
    }
    return {};
}
int main(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());
    int l=0,r=n-1;
    while(l<r){
        int sum=v[l].first+v[r].first;
        if(sum < m){
            ++l;
        }else if(sum > m){
            --r;
        }else{
            cout<<v[l].second+1<<' '<<v[r].second+1<<endl;return 0;
        }
    }
    cout<<"imposible";
    return 0;
}