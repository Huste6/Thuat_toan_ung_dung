#include<bits/stdc++.h>
using namespace std;

typedef struct job{
    int jobid,deadline,profit;
}job;

//neu deadline la x thi moc thoi gian hop le la 0,x-1
//0 -> 1 -> 2 -> 3 -> 4 ....
bool cmp(job a,job b){
    return a.profit > b.profit;
}

int main(){
    int n;cin>>n;
    job a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].jobid>>a[i].deadline>>a[i].profit;
    }
    sort(a,a+n,cmp);
    bool used[n];
    memset(used,false,sizeof(used));
    int ans=0;
    int mark[n];
    for(int i=0;i<n;i++){
        for(int j=a[i].deadline-1;j>=0;j--){
            if(used[j]==false){
                //moc thoi gian thu j chua duoc su dung
                ans+=a[i].profit;
                used[j]=true;
                //mark[j]=i;//cong viec thu i duoc thuc hien o moc thoi gian j 
                break;
            }
        }
    }
    cout<<ans<<endl;
}