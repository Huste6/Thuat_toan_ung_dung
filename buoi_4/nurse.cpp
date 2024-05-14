/*
	- chuỗi 1 liên tiếp >= k1 <= k2
	- Giữa các chuỗi 1 có đúng 1 bit 0
	=> a1[i] la so xau nhi phan do dai i, bit i = 0
	=> b1[i] la so xau nhi phan do dai i, bit i = 1
	a1[i] = b1[i-1]
	b1[i] = sigma(k1 <= i - j <= k2) a1[j]
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int a1[1002],b1[1002];
int main(){
    int n,k1,k2;cin>>n>>k1>>k2;
    a1[0]=b1[0]=1;
    for(int i=1;i<=n;i++){
        a1[i]=b1[i-1]%mod;
        for(int k=k1;k<=k2;k++){
            int j=i-k;
            if(j>=0) b1[i]+=a1[j];
            b1[i]%=mod;
        }
    }
    cout<<(a1[n]+b1[n])%mod;
}