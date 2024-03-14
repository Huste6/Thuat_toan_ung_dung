#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int x[100],n;
void Try(int i){
    for(int j=0;j<=1;j++){
        x[i]=j;
        if(i==n){
            for(int i=1;i<=n;i++){
                cout<<x[i];
            }
            cout<<endl;
        }else Try(i+1);
    }
    
}
int main(){
    cin>>n;
    Try(1);
}