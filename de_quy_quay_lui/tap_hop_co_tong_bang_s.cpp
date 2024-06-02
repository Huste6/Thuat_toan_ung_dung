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
/*
#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int cnt=0;
void inp(){
    cin>>n>>k>>s;
}
void backTrack(int u,int pos,int sum){
    if(u==k && sum == s){
        cnt++;
        return;
    }
    if(u>=k || sum >=s) return;
    for(int i=pos;i<=n;i++){
        backTrack(u+1,i+1,sum+i);
    }
}
int main(){
    inp();
    backTrack(0,1,0);
    cout<<cnt;
}*/
