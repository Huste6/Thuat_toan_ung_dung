// Nguyen Ngoc Quan
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e3+1; 
ll matrix[maxn][maxn]; 
int maxx=0;
int maxy=0;
ll ans=0;
void nhap(){
    int n;
    cin>>n;
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<n;i++){ 
        int xi,yi,ci;
        cin>>xi>>yi>>ci;
        maxx=max(maxx,xi);
        maxy=max(maxy,yi);
        matrix[xi][yi]=ci;
    }
}
void solve(){
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            if(i==1 && j==1){
                matrix[i][j]=matrix[i][j];
            }else if(i==1){
                matrix[i][j]+=matrix[i][j-1];
            }else if(j==1){
                matrix[i][j]+=matrix[i-1][j];
            }else{
                matrix[i][j]+=max({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]});
            }
        }
    }
    cout<<matrix[maxx][maxy];
}
int main(){
    nhap();
    solve();
    return 0;
}
