#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int x[100],n;
int cot[100],d1[100],d2[100],res=0;
//x[i]=j;//con hau hang thu i nam o cot j
int a[100][100];
void ktao(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    memset(cot,0,sizeof(cot));
    memset(d1,0,sizeof(cot));
    memset(d2,0,sizeof(cot));
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]==0 && d1[i-j+n]==0 && d2[i+j-1]==0){
            x[i]=j;
            cot[j]=1; 
            d1[i-j+n]=1;
            d2[i+j-1]=1;
            if(i==n){
                int sum=0;
                for(int k=1;k<=n;k++){
                    sum+=a[k][x[k]];
                }
                res=max(res,sum);
            }
            Try(i+1);
            cot[j]=0; 
            d1[i-j+n]=0;
            d2[i+j-1]=0;
        }        
    }
}
int main(){
    cin>>n;
    ktao();
    Try(1);
    cout<<res;
}