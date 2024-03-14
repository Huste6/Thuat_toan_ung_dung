#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
//c1: quay lui rat hay
int n;
int a[]={4,7};
int sum=0;
int x[100];
bool ok=true;
void inp(){
    cin>>n;
}
void Try(int i,int sum,int pos){
    if(sum==n){
        ok=true;
        for(int j=0;j<i;j++) cout<<x[j];
        cout<<endl;
        return;
    }
    if(sum>n || pos>=2) {
        return  ;
    }
    for(int j=pos;j<2;j++){
        if(sum+a[j]<=n){
            x[i]=a[j];
            Try(i+1,sum+a[j],j); 
        }
    }
}
int main(){
    inp();
    Try(0,0,0);
    if(ok==false) cout<<-1;
}*/
//c2: tham lam
int main(){
    int n;cin>>n;
    for(int b=n/7;b>=0;b--){
        int tmp=n-b*7;
        if(tmp%4==0){
            cout<<string(tmp/4,'4')<<string(b,'7');
            return 0;
        }
    }
    cout<<-1;
    return 0;
}