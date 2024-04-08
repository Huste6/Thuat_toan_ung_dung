#include<bits/stdc++.h>
using namespace std;
int H,W;
int n;
int h[11],w[11];
bool mark[11][11];
bool ok=false;
int x[11],y[11],o[11];
// o nhan gia tri 1 neu thanh kim loai can xoay 90
// o nhan gia tri 0 neu giu nguyen thanh kiem loai
void inp(){
    cin>>H>>W>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>w[i];
    }
    memset(mark,false,sizeof(mark));
}
bool check(int vo,int vx,int vy,int k){
    int wk=w[k],hk=h[k];
    if(vo==1){
        wk=h[k];hk=w[k];
    }
    if(vx+wk > W) return false;
    if(vy+hk > H) return false;
    for(int i=vx;i<=vx+wk-1;i++){
        for(int j=vy;j<=vy+hk-1;j++){
            if(mark[i][j]) return false;
        }
    }
    return true;
}
void danhdau(int vx,int vy,int vo,int k,bool mark_val){
    int wk=w[k],hk=h[k];
    if(vo==1){
        wk=h[k],hk=w[k];
    }
    for(int i=vx;i<=vx+wk-1;i++){
        for(int j=vy;j<=vy+hk-1;j++){
            mark[i][j]=mark_val;//co the la danh dau true neu ghep duoc hoac false neu minh go thanh kim loai ra
        }
    }
}
void Try(int k){
    if (ok) return;
    for(int vo=0;vo<=1;vo++){
        int wk=w[k],hk=h[k];
        if(vo==1){
            wk=h[k],hk=w[k];
        }
        for(int vx=0;vx<=W-wk;vx++){ 
            for(int vy=0;vy<=H-hk;vy++){ 
                if(check(vo,vx,vy,k)){
                    x[k]=vx,y[k]=vy,o[k]=vo;
                    danhdau(vx,vy,vo,k,true);
                    if(k==n){
                        ok=true;
                        return;
                    } else {
                        Try(k+1);
                    }
                    danhdau(vx,vy,vo,k,false);
                }
            }
        }
    }
}


int main(){
    inp();
    Try(1);
    if(ok==true) cout<<"1";
    else cout<<"0";
}