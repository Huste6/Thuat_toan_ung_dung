// cho 1 mang a1,a2,a3,a4,...,an tìm số cặp (i,j,k) sao cho giữa 3 số ai,aj,ak thì có 1 số bằng tổng 2 số còn lại
// input:
// 6
// 9 5 4 3 8 1
// output: 5

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n;
int a[2001];
int cnt=0;

void inp(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
// su dung hash
void solve(){
    unordered_map<int,int> mp;
    for(int num:a){
        mp[num]++;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(mp.find(a[i]+a[j]) != mp.end()){
                cnt++;
                cout<<a[i]<<' '<<a[j]<<endl;
            }
        }
    }
    cout<<cnt%mod;
}
int main(){
    inp();
    solve();
    return 0;
}