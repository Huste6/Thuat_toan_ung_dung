//kiem tra ko in ra phan tu trung
#include<bits/stdc++.h>
using namespace std;
int cnt[1000001];//mang danh dau
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    /*for(int i=0;i<n;i++){
        bool check=true;
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                check=false;
                break;
            }
        }
        if(check) cout<<a[i]<<" ";
    }*/
    int max_val=-1e9;
    for(int i=0;i<n;i++){
        cnt[a[i]]=1; //O(1)'
        max_val=max(max_val,a[i]);
    }
    int dem=0;
    for(int i=0;i<=max_val;i++){
        if(cnt[i]==1){ //O(1)
            dem++;
            //cout<<i<<' ';
        }
    }
    cout<<dem<<endl;
}