#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
string s;
char a[100];int visited[100];
void ktao(){
    cin>>s;
    memset(visited,0,sizeof(visited));
}
void Try(int i){
    if(i == s.size()) {
        for(int k = 0; k < s.size(); k++) {
            cout << a[k];
        }
        cout << " ";
        return;
    }
    for(int j = 0; j < s.size(); j++){
        if(visited[j] == 0){
            a[i] = s[j];
            visited[j] = 1;
            Try(i + 1);
            visited[j] = 0;
        }
    }
}
int main(){
    ktao();
    Try(0);
}