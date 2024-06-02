#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n, s, a[100], x[100], sum = 0;
bool ok = false;
vector<vector<int>> vt;

void inp() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
}

void Try(int i, int pos) {
    if(sum == s) {
        ok = true;
        vector<int> tmp(x+1, x + i);
        sort(tmp.begin(), tmp.end());
        vt.push_back(tmp);
        return;
    }
    for(int j = pos; j <= n; j++) {
        if(sum+a[j]<=s){
            x[i] = a[j];
            sum += a[j];
            Try(i + 1, j);
            sum -= a[j];
        }
    }
}

int main() {
    inp();
    Try(1, 1);
    if(!ok) 
        cout << "-1";
    else {
        sort(vt.begin(), vt.end());
        for(auto it : vt) {
            cout << "{";
            for(int i = 0; i < it.size(); i++) { 
                cout << it[i];
                if(i != it.size() - 1) 
                    cout << " ";
            }
            cout << "}\n";
        }
    }
    return 0;
}
/*
chu y bai toan minh phai co 1 nhanh can sum+a[j]<=s
input:
3 10
4 2 3
output:
{2 2 2 2 2}
{2 2 2 4}
{2 2 3 3}
{2 4 4}
{3 3 4}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[100],x[100];
vector<vector<int>> ans;
void inp(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
}
void Try(int i,int sum,int pos){
    if(sum==s){
        vector<int> tmp(x+1,x+i);
        ans.push_back(tmp);
        return;
    }
    if(sum>=s) return;
    for(int j=pos;j<=n;j++){
        x[i]=a[j];
        Try(i+1,sum+a[j],j);
    }
}
int main(){
    inp();
    Try(1,0,1);
    for(auto it:ans){
        cout<<'{';
        for(int x:it) cout<<x<<' ';
        cout<<'}';
        cout<<'\n';
    }
    return 0;
}
*/