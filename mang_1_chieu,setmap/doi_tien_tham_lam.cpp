#include<bits/stdc++.h>
using namespace std;
int tien[]={1000,500,200,100,50,20,10,5,2,1};
int main(){
    long long n;cin>>n;
    int idx=0;
    long long cnt=0;
    while(n!=0){
        cnt+=n/tien[idx];
        n=n%tien[idx];idx++;
    }
    cout<<cnt;
}