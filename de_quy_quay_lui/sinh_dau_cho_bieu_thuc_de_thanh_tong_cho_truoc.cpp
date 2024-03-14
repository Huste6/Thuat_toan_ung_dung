/*
cho bieu thuc [[[A op(1) B] op(2) C] op(3) D] op(4) E
chen + - * vao op de bieu thuc bang 23
A B C D E co the duoc thay doi cho nhau
5! * 4A3 cach xep

*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

vector<vector<int>> hoanvi,chinhhop;
int x[100],a[100];
void Try(int i){
    for(int j=1;j<=3;j++){
        x[i]=j;
        if(i==3){
            vector<int> tmp(x+1,x+5);
            chinhhop.push_back(tmp);
        }else Try(i+1);
    }
}
void init(){
    int b[]={1,2,3,4,5};
    do{
        vector<int> tmp(b,b+5);
        hoanvi.push_back(tmp);
    }while(next_permutation(b,b+5));
    Try(1);
}
// sinh hoan vi 12345 12354.....
// sinh chinh hop 111 112 113 .....
int main(){
    int t;cin>>t;
    while(t--){
        init();
        for(int i=1;i<=5;i++) cin>>a[i];
        bool ok=false;
        for(auto it1:hoanvi){
            for(auto it2:chinhhop){
                int res=a[it1[0]];
                for(int k=0;k<4;k++){
                    if(it2[k]==1){
                        res+=a[it1[k+1]];
                    }else if(it2[k]==2){
                        res-=a[it1[k+1]];
                    }else{
                        res*=a[it1[k+1]];
                    }
                }
                if(res==23){
                    ok=true;break;
                }
            }
            if(ok) break;
        }
        if(ok==true) cout<<"YES";
        else cout<<"NO";
    }
}