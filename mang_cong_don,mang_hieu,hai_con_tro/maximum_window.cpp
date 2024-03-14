#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;cin>>n>>k;
    int a[n];
    for(int &x:a) cin>>x;
    multiset<int> se;
    for(int i=0;i<k;i++){
        se.insert(a[i]);
    }
    cout<<*se.begin()<<' '<<*se.rbegin()<<endl;
    for(int i=k;i<n;i++){
        se.erase(a[i-k]);
        se.insert(a[i]);
        cout<<*se.begin()<<' '<<*se.rbegin()<<endl;
    }
}