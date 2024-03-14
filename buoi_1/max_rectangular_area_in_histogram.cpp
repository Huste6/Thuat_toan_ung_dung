#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int res=-1e9;
    stack<int> st;
    int i=0;
    while(i<n){
        if(st.empty() || a[i] >= a[st.top()]){
            st.push(i);i++;
        }else{
            int index=st.top();
            st.pop();
            if(st.empty()){
                res=max(res,i*a[index]);
            }else{
                res=max(res,(i-st.top()-1)*a[index]);
            }
        }
    }
    while(!st.empty()){
        int index=st.top();
        st.pop();
        if(st.empty()){
            res=max(res,i*a[index]);
        }else{
            res=max(res,(i-st.top()-1)*a[index]);
        }
    }
    cout<<res<<endl;
}