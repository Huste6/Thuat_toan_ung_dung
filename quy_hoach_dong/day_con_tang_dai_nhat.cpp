#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> L(n,1);int ans=0;
    for(int i=0;i<n;i++){
        //duyet qua cac phan tu dung truoc i
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                L[i]=max(L[i],L[j]+1);
            }
        }
        ans=max(ans,L[i]);
    }
    cout<<ans<<endl;
    cout<<*max_element(L.begin(),L.end())<<endl;
}