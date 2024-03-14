//sinh ra n so nguyen to lon hon P va co tong bang s (dua ra tat ca cac th)
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool nt(ll n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int n,p,s,x[100];
vector<int> nto;
vector<vector<int>> res;
bool ok=false;
void inp(){
    nto.clear();
    res.clear();
    cin>>n>>p>>s;
    for(int i=p+1;i<=s;i++){
        if(nt(i)==true) nto.push_back(i);
    }
}
void Try(int i,int sum,int pos){
    if(i==n && sum==s){
        vector<int> tmp(x,x+n);
        res.push_back(tmp);
    }
    for(int j=pos;j<=nto.size();j++){
        if(sum+nto[j]<=s){
            x[i]=nto[j];
            Try(i+1,sum+nto[j],j+1);
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        inp();
        Try(0,0,0);
        cout<<res.size()<<endl;
        for(auto it:res){
            cout<<"[";
            for(int x:it){
                cout<<x<<" ";
            }
            cout<<"] ";
        }
        cout<<endl;
    }
}
/*
inp: 
2
2 7 28
3 2 23
out:
[11 17 ]
[3 7 13 ] [5 7 11 ]
*/