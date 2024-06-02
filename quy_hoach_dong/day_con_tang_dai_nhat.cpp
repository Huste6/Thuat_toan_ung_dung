#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> L(n,1);int ans=0;
    for(int i=0;i<n;i++){
        //duyet qua cac phan tu dung truoc i
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                L[i]=max(L[i],L[j]+1);
            }
        }
        ans=max(ans,L[i]);
    }
    cout<<ans<<endl;
    cout<<*max_element(L.begin(),L.end())<<endl;
}
/*https://oj.vnoi.info/problem/lis*/
// ib de dck giai thich code :)) 
/*
#include<bits/stdc++.h>
using namespace std;

int a[30001];
int b[30001];
int n;
int max_b; //luu do dai cua mang b --> no duyet tang dan
void inp(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
int binary_search(int x){
    int ans=0;
    int l=1,r=max_b;
    while(l<=r){
        int mid = (l+r)/2;
        if(b[mid] < x){
            ans=mid;
            l=mid+1;
        }else r = mid - 1;
    }
    return ans;
}
int main(){
    inp();
    for(int i=1;i<=n;i++){
        int j= binary_search(a[i]);//so lon nhat trong mang b nho hon a[i]
        b[j+1]=a[i];
        max_b=max(max_b,j+1);
    }
    cout<<max_b;
}

*/