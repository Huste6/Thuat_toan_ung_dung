#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD = 1e9+7;
int cnt1[10000001],cnt2[10000001];
/*int main(){
    int n,m;cin>>n>>m;
    int a[n];
    set<int> b,b1;
    for(int &x:a) cin>>x;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        b.insert(x);
        b1.insert(x);
    }
    sort(a,a+n);
    for(int x:a){
        if(b.count(x)!=0){
            cout<<x<<" ";
            b.erase(x);
        }
    }
    cout<<endl;
    for(int x:a){
        if(b1.count(x)==0){
            b1.insert(x);
        }
    }
    for(auto it:b1){
        cout<<it<<' ';
    }
}*/
int main(){
    int n,m;cin>>n>>m;
    int a[n],b[m],MAX=-MOD,MIN=MOD;
    for(int &x:a){
        cin>>x;cnt1[x]++;
        MAX=max(MAX,x);
        MIN=min(MIN,x);
    }
    for(int &x:b){
        cin>>x;cnt2[x]++;
        MAX=max(MAX,x);
        MIN=min(MIN,x);
    }
    for(int i=MIN;i<=MAX;i++){
        if(cnt1[i]>0 && cnt2[i]>0){
            cout<<i<<' ';
        }
    }
    cout<<endl;
    for(int i=MIN;i<=MAX;i++){
        if(cnt1[i]>0 || cnt2[i]>0){
            cout<<i<<' ';
        }
    }
}