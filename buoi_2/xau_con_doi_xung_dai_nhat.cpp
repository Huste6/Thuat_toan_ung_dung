#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    s='x'+s;
    //f[i][j] xau con bat dau tu chi so i den chi so j
    //f[i][j] = f[i+1][j-1] &&  s[i]==s[j]
    bool f[n+1][n+1];
    memset(f,false,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=true;
    //xet xau con co do dai tu 1 den n
    int ans=1;
    for(int sz=2;sz<=n;sz++){
        for(int i=1;i<=n-sz+1;i++){
            int j=i+sz-1;
            if(sz==2 && s[i]==s[j]) f[i][j]=true;
            else{
                if(s[i] != s[j] ) f[i][j]=false;
                else{
                    f[i][j]=f[i+1][j-1];
                }
            }
            if(f[i][j]) ans=max(ans,sz);
        }
    }
    cout<<ans<<endl;
}