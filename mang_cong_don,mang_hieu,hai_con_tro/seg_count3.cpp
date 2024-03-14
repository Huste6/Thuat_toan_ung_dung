#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//co bao nhieu mang con ma trong do so phan tu khac nhau nho hon k
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;int cnt=0,l=0,res=0;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(mp[a[i]]==1) ++cnt;
        while(cnt>k){
            mp[a[l]]--;
            if(mp[a[l]]==0) --l;
            l++;
        }
        res+=i-l+1;
    }
    cout<<res<<endl;
}