#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n,x[100];bool visited[100];
void inp(){
    cin>>n;
    memset(visited,false,sizeof(visited));
}
bool check(int n){
    vector<int> res;
    while(n>0){
        res.push_back(n%10);
        n/=10;
    }
    reverse(res.begin(),res.end());
    for(int i=1;i<res.size();i++){
        if(res[i]==0) return false;
        if(abs(res[i]-res[i-1])==1) return false;
    }
    return true;
}
void Try(int i){
    if (i > n) {
        ll num = 0;
        for (int j = 1; j <= n; ++j) {
            num = num * 10 + x[j];
        }
        if (check(num)) {
            cout << num << endl;
        }
        return;
    }
    for(int j=1;j<=n;j++){
        if(!visited[j]){
            visited[j]=true;
            x[i]=j;
            Try(i+1);
            visited[j]=false;
        }
    }

}
int main(){
    inp();
    Try(1);
}