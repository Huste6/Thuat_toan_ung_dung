#include<bits/stdc++.h>
using namespace std;
void solve(int n,int a[]){
    stack<pair<string,vector<bool>>> st;
    vector<bool> init_used(n,false);
    st.push({"",init_used});
    while(!st.empty()){
        auto [currstr,used] = st.top();
        st.pop();
        if(currstr.size()==n){
            cout<<currstr<<endl;
        }else{
            for(int i=0;i<n;i++){
                if(!used[i]){
                    used[i]=true;
                    st.push({currstr+to_string(a[i]),used});
                    used[i]=false;
                }
            }
        }
    }
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int &x:a) cin>>x;
    solve(n,a);
    return 0;
}