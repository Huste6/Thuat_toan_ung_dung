#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1001][1001];
int matrix[1001][1001];
int ans=-1e9;

int max_rectangle(int a[],int n){
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
    return res;
}
void inp(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>a[i][j];
    }
    memset(matrix,0,sizeof(matrix));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1) matrix[i][j]=matrix[i-1][j]+1;
        }
    }
    for(int i=0;i<n;i++){
        ans=max(ans,max_rectangle(matrix[i],m));
    }
    cout<<ans<<endl;
}

int main(){
    inp();
}