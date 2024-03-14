#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tuso,mauso;
void inp(){
    cin>>tuso>>mauso;
}
void Try(ll tuso,ll mauso){
    if(mauso%tuso==0){
        cout<<1<<"/"<<mauso/tuso<<endl;
        return;
    }
    ll x=mauso/tuso+1;
    cout << 1 << "/" << x << " + ";
    ll mausomoi=mauso*x;
    ll tusomoi=tuso*x-mauso;
    Try(tusomoi,mausomoi);
}
int main(){
    inp();
    Try(tuso,mauso);
    return 0;
}