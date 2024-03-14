#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int sum(int n){
    int res=0;
    while(n){
        res+=n%10;n/=10;
    }
    return res;
}
bool cmp(int a,int b){
    if(sum(a)!=sum(b)) return sum(a)<sum(b);
    return a<b;
}
int main(){
    int n=5;
    int a[5]={22,6,4,9,33};
    sort(a,a+n,cmp);
    for(auto x:a) cout<<x<<' ';
    return 0;
}