#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
bool F[201][1001];
int main(){
    int c,n;cin>>c>>n;
    int a[n];int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) {
        F[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j>=a[i]){
                F[i][j]=F[i-1][j-a[i]] || F[i-1][j];
            }else F[i][j]=F[i-1][j];
            if(F[i][j]) ans=max(ans,j);
        }
    }
    cout<<ans;
}