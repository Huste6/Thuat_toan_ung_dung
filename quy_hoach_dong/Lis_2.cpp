#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
    faster();
    int n;cin>>n;
    int a[n+1];
    int F[n+1],giam_nguoc[n+1];int res=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    F[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1]) F[i]=F[i-1]+1;
        else F[i]=1;
        res=max(res,F[i]);
    }
    giam_nguoc[n]=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1]) giam_nguoc[i]=giam_nguoc[i+1]+1;
        else giam_nguoc[i]=1;
    }
    //xoa thu tung so mot
    for(int i=2;i<=n-1;i++){
        if(a[i-1]<a[i+1]){
            res=max(res,giam_nguoc[i+1]+F[i-1]);
        }
    }
    cout<<res<<endl;
}