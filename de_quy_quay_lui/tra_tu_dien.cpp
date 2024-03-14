#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char a[100][100];
int visited[100][100];
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,-1,-1,0,1,1};
set<string> dict;
int k,n,m;
string s="";
vector<string> res;

void input(){
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        string word; cin>>word;
        dict.insert(word);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    memset(visited,0,sizeof(visited));
}

void Try(int i,int j){
    s+=a[i][j];
    if(dict.count(s)){
        res.push_back(s);
    }
    for(int k=0;k<8;k++){
        int i1=i+dx[k];
        int j1=j+dy[k];
        if(i1>=1 && i1<=n && j1<=m && j1>=1 && visited[i1][j1]==0){
            visited[i1][j1]=1;
            Try(i1,j1);
            visited[i1][j1]=0;
        }
    }
    s.pop_back();
}

int main(){
    input();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]==0){
                Try(i,j);
            }
        }
    }
    sort(res.begin(),res.end());
    for(string s1 : res){
        cout << s1 << " ";
    }
    return 0;
}
/*4 3 3  
GEEKS FOR QUIZ GO
G I Z
U E K
Q S E*/