#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
bool F[1001][1001];
int main(){
    int n;cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    for(int i=0;i<=n;i++) {
        F[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=1;j--){
            if(j>=a[i]){
                F[i][j]=F[i-1][j-a[i]] || F[i-1][j];
            }
        }
    }
    for(int j=0;j<=sum;j++){
        for(int i=1;i<=n;i++){
            if(F[i][j]){
                cout<<j<<" ";
                break;
            }
        }
    }
}