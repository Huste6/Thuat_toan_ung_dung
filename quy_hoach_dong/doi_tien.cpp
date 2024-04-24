#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int N=20;
const int Xmax=1e5+5;
int D[N],mem[N][Xmax];
int n,sum;
void nhap(){
    cin>>n>>sum;
    for(int i=1;i<=n;i++) cin>>D[i];
    memset(mem,-1,sizeof(mem));
}
int minCOin(int i,int x){
    if(x<0 || i==0) return INF;
    if(x==0) return 0;
    if(mem[i][x]==-1) return mem[i][x];
    int res=INF;
    res=min({res,1+minCOin(i,x-D[i]),minCOin(i-1,x)});
    return mem[i][x]==res;
}
int main(){
    nhap();
    cout<<minCOin(n,sum);
}