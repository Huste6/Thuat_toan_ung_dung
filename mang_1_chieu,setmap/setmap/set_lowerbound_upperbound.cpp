#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> ms;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        ms.insert(x);
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        if(a==1){
            ms.insert(b);
        }else if(a==2){
            //if(ms.count(b)!=0) ms.erase(b);
            if(ms.find(b)!=ms.end()) ms.erase(ms.find());
        }else if(a==3){
            auto it = ms.lower_bound(b);
            if(it!=ms.end()){
                cout<<*it;
            }else cout<<"-1";
            cout<<endl;
        }else if(a==4){
            auto it = ms.upper_bound(b);
            if(it!=ms.begin()){
                cout<<*(--it);
            }else cout<<"-1";
            cout<<endl;
        }
    }
}