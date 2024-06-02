#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool isprime[502];
int n,k,sum=0;
int x[10];
bool visited[502];
vector<vector<int>> vt;

void sieve(){
    for(int i=0;i<=501;i++){ 
        isprime[i]=true;
    }
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=501;i++){
        if(isprime[i]==true){
            for(int j=i*i;j<=501;j+=i){
                isprime[j]=false;
            }
        }
    }
}

void inp(){
    cin>>n>>k;
    sieve();
    memset(visited,false,sizeof(visited));
}
/*
bool isPrime(int num){
    if(num <= 1) return false;
    for(int i = 2; i*i <= num; ++i){
        if(num % i == 0) return false;
    }
    return true;
}*/

void Try(int i,int pos){
    if(i==k+1 && sum==n){
        vector<int> tmp(x+1,x+i);
        sort(tmp.begin(),tmp.end());
        vt.push_back(tmp);
        return;
    }
    for(int j=pos;j<=n;j++){
        if(!visited[j] && isprime[j]){
            x[i]=j;
            visited[j]=true;
            sum+=j;
            Try(i+1,j+1);
            visited[j]=false;
            sum-=j;
        }
    }
}

int main(){
    inp();
    Try(1,1);
    if(vt.empty()){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        for(auto it:vt){
            for(int i=0;i<it.size();i++){
                cout<<it[i];
                if(i!=it.size()-1) cout<<" + ";
            }
            cout<<endl;
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

bool isprime[502];
int n, k;
vector<vector<int>> vt;
int x[502];

void seive() {
    fill(isprime, isprime + 502, true); 
    isprime[0] = isprime[1] = false; 
    for (int i = 2; i <= 501; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= 501; j += i) {
                isprime[j] = false;
            }
        }
    }
}

void inp() {
    cin >> n >> k;
    seive();
}

void Try(int i, int pos, int sum) {
    if (i == k) {
        if (sum == n) {
            vector<int> ans(x, x + k);
            vt.push_back(ans);
        }
        return;
    }
    for (int j = pos; j <= n; j++) {
        if (isprime[j]) {
            x[i] = j;
            Try(i + 1, j + 1, sum + j);
        }
    }
}

int main() {
    inp();
    Try(0, 1, 0); 
    for (const auto& it : vt) {
        for (int x = 0; x < it.size(); x++) {
            cout << it[x];
            if (x != it.size() - 1) cout << '+';
        }
        cout << '\n';
    }
    return 0;
}

*/