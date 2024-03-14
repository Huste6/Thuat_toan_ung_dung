#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[100],n;
void ktao(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
}
void Try(int i){
    if(i<=0) return;
    cout<<"[";
    for(int j=1;j<=i;j++){
        cout<<a[j];
        if(j==i) cout<<"] ";
        else cout<<" ";
    }
    //xay dung mang tiep
    for(int j=1;j<i;j++){
        a[j]+=a[j+1];
    }
    Try(i-1);
}
//in nguoc lai
void Try1(int i){
    if(i<=0) return;
    //xay dung mang tiep
    for(int j=1;j<i;j++){
        a[j]+=a[j+1];
    }
    Try(i-1);
    cout<<"[";
    for(int j=1;j<=i;j++){
        cout<<a[j];
        if(j==i) cout<<"] ";
        else cout<<" ";
    }
    for(int j=i;j>=1;j--){
        a[j]-=a[j+1];
    }
}
int main(){
    ktao();
    Try(n);
}
/*
input:
5
1 2 3 4 5
output: [1 2 3 4 5] [3 5 7 9] [8 12 16] [20 28] [48]
output_2: [48] [20 28] [8 12 16] [3 5 7 9] [1 2 3 4 5]
*/