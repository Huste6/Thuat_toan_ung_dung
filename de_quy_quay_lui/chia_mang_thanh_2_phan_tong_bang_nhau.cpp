#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[100],sum=0;
void inp(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2) {
        cout<<"NO";return;
    }
    bool mark[sum/2];
    memset(mark,false,sizeof(mark));
    for(int i=0;i<n;i++){
        for(int j=sum/2;j>=a[i];j--){
            if(mark[j]-a[i] ==1 || j==a[i]){
                mark[j]=true;
            }
        }
    }
    if(mark[sum/2]) cout<<"YES";
}
int main(){
    inp();
}