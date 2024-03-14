#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll n){
    ll can=cbrt(n) + 0.5;
    return can*can*can == n;
}
ll res=0;
int x[100],n;
string s;
bool ok=false;
//giai thich code:
//minh se sinh ra chuoi nhi phan co do dai n va khi no sinh duoc 1 cau hinh
//thi tao 1 sum cong het cac so o chi so i co bit la 0 (bit 1 o vi tri k co nghia la bo di so o vi tri k, bit 0 la lay so o vi tri k) 
void Try(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n-1){
            ll tmp=0;
            for(int k=0;k<n;k++){
                if(x[k]){
                    tmp=tmp*10+(s[k]-'0');
                }
            }
            if(check(tmp) && tmp>res){
                ok=true;
                res=tmp;
            }
        }else Try(i+1);
    }
}
int main(){
    cin>>s;
    n=s.size();
    Try(0);
    if(!ok) cout<<"-1";
    else cout<<res;
    return 0;
}
//input: 4125 thi output: 125 = 5^3