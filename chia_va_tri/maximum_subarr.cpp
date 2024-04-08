#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll crossing_sum(int a[],int l,int r,int m){
    int sum_left=0,max_sum_left=0;
    int sum_right=0,max_sum_right=0;
    for(int i=m;i>=l;i--){
        sum_left+=a[i];
        max_sum_left=max(max_sum_left,sum_left);
    }
    for(int i=m+1;i<=r;i++){
        sum_right+=a[i];
        max_sum_right=max(max_sum_right,sum_right);
    }
    return max_sum_right+max_sum_left;
}
ll max_sum(int a[],int l,int r){
    if(l==r) return a[l];
    int m=(l+r)/2;
    return max({max_sum(a,l,m),max_sum(a,m+1,r),crossing_sum(a,l,r,m)});
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    cout<<max_sum(a,0,n-1);
}