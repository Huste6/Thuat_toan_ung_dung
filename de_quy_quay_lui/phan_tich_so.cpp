#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool ok=false;
int n,s,a[100];
int x[100];
void inp(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
//neu pos xet tu j+1 thi no se in cac phan tu ko trung nhau nhung o day de bai cac phan tu duoc lap lai nhieu lan nen pos xet tu i
void Try(int sum,int i,int pos){
    if(sum==s){
        cout<<"[";
        for(int j=1;j<i;j++){
            cout<<x[j];
            if(j==i-1) cout<<"] ";
            else cout<<" ";
        }
        ok=1;
        return;
    }
    for(int j=pos;j<=n;j++){
        if(sum+a[j]<=s){
            x[i]=a[j];
            Try(sum+a[j],i+1,j);
        }
    }
}
int main(){
    inp();
    Try(0,1,1);
    if(!ok) cout<<"-1";
    else cout<<"\n";
}
/*
inp:
4 8       
2 4 6 8
oup:
[2 2 2 2] [2 2 4] [2 6] [4 4] [8]
*/