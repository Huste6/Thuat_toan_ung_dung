#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    sort(a,a+n);//chi de chac chan cac vi  tri duoc xep tu be den lon
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<abs(a[0]-a[1])<<' '<<abs(a[0]-a[n-1])<<endl;
        }else if(i==n-1){
            cout<<abs(a[n-1]-a[n-2])<<' '<<abs(a[n-1]-a[0])<<endl;
        }else{
            cout<<min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]))<<' '<<max(abs(a[n-1]-a[i]),abs(a[0]-a[i]))<<endl;
        }
    }
    return 0;
}