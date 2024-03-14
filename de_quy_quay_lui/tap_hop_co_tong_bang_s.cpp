#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,k,s,cnt=0,sum=0,res=0;
int x[100];
void Try(int i){
    for(int j=x[i-1]+1;j<=n;j++){
        x[i]=j;
        cnt++;
        sum+=j;
        if(cnt==k && sum==s){
            res++;
            cout<<"[";
            for(int f=1;f<=k;f++){
                cout<<x[f]<<" ";
            }
            cout<<"]\n";
        }else Try(i+1);
        cnt--;
        sum-=j;
    }
}
int main(){
    cin>>n>>k>>s;
    Try(1);
    cout<<endl;
    cout<<res;
}