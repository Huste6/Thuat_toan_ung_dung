#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;int n;
using ll=long long;
int a[maxn],t[4*maxn];

//t[v] tong cac phan tu chi so l->r
void build(int v,int l,int r){
    if(l==r){
        t[v]=a[l];//cac node la
    }else{  
        int m=(l+r)/2;
        build(2*v,l,m);
        build(2*v+1,m+1,r);
        t[v]=t[2*v]+t[2*v+1];
    }
}

//query:O(logn) a[l,r]
int sum(int v,int tl,int tr,int l,int r){
    if(l>r) return 0;
    if(l==tl && r==tr) return t[v];
    else{
        int tm=(tl+tr)/2;
        return sum(2*v,tl,tm,l,min(tm,r))+sum(2*v+1,tm+1,tr,max(tm+1,l),r);
    }
}

//update: O(logn) a[pos]=val
void update(int v,int l,int r,int pos,int val){
    if(l==r){
        t[v]=val;
    }else{
        int m=(l+r)/2;
        if(pos<=m) update(2*v,l,m,pos,val);
        else update(2*v+1,m+1,r,pos,val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
/*
6 
1 3 5 7 9 11
*/
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    cout<<sum(1,0,n-1,2,4);
}