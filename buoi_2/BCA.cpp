#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,m;
vector<int> a[35];
int x[35],load[35];
//a[i] is the list of teachers can teach the course i
//x[i] is the teacher assigned to course i
//load[i] is the number of course assigned to teacher i
bool cfl[35][35];
bool ok=false;int obj=1e9+1;

void inp(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++){
            int x;cin>>x;
            a[x].push_back(i);
        }
    }
    int k;cin>>k;
    memset(cfl,false,sizeof(cfl));
    while(k--){
        int x,y;cin>>x>>y;
        cfl[x][y]=cfl[y][x]=true;
    }
}
//mon hoc k , giao vien v 
//kiem tra cac mon hoc truoc k thi giao vien v da day mon nao ma trung tg voi k ko
bool check(int v,int k){
    for(int i=1;i<=k-1;i++){
        if(cfl[i][k]==true && x[i]==v){
            //neu i va k trung thoi gian 
            //giao vien v duoc phan cong day mon i
            return false;
        }
    }
    return true;
}
void Try(int k){
    for(int v:a[k]){
        //duyet tat ca giao vien co the day mon k
        if(check(v,k)){
            x[k]=v;load[v]++;
            if(k==n){
                ok=true;
                int maxload=*max_element(load+1,load+m+1);
                obj=min(obj,maxload);
            }else if(load[v] < obj) Try(k+1);
            load[v]--;
        }
    }
}
int main(){
    inp();
    Try(1);
    if(ok) cout<<obj<<endl;
    else cout<<-1<<endl;
}