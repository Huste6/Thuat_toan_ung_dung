#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int F[501][501];
int main(){
    int n;cin>>n;
    int sum=0;
    int res=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    if(sum%2==0){
        sum/=2;
        for(int i = 0; i <= n; i++){
            F[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=sum;j>=1;j--){
                if(j>=i){
                    F[i][j]=F[i-1][j-i]+F[i-1][j];
                    if(j==sum && i==n){
                        res=F[i-1][j-i];
                    }
                }
                else F[i][j]=F[i-1][j];
                F[i][j]%=mod;
            }
        }
        cout<< res<<endl;
    }else cout<<0<<endl;
}