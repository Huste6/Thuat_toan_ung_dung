#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,s;cin>>n>>s;
    int a[n];
    for(int &x:a) cin>>x;
    int dem[1000001]={0};
    int ans=0;
    int l=0;
    for(int i=0;i<n;i++){
        dem[a[i]]++;
        if(dem[a[i]]==1) ++cnt;
        while(cnt>k){
            if(dem[a[i]]==1) --cnt;
            ++l;dem[a[i]]--;
        }
        ans+=r-l+1;
    }
    cout<<ans;
}