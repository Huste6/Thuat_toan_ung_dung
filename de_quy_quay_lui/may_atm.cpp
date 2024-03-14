#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100],n,s,x[100],sum=0,ans=0,res=1e9+1;bool ok=false;
vector<int> vt;
void Try(int i,int pos){
    for(int j=pos;j<n;j++){
        x[i]=a[j];
        sum+=a[j]; 
        if(sum==s){
            ok=true;
            for (int f = 0; f <= i; f++) {
                ans++;
            }
            if(res>ans){
                vt.clear();
                res=ans;
                for (int f = 0; f <= i; f++) {
                    vt.push_back(x[f]);
                }
            }
        }else Try(i+1,j+1);
        sum-=a[j];
    }
}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+1,greater<int>());
    Try(0,0);
    if(!ok){
        cout<<-1;return 0;
    }
    for(int x:vt){
        cout<<x<<" ";
    }
    return 0;
}