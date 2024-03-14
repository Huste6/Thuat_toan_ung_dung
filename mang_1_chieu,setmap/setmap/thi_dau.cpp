#include<bits/stdc++.h>
using namespace std;
//getline thi truoc do phai co cin.ignore
int tim(string s,char x){
    for(int i=0;i<s.length();i++){
        if(s[i]==x) return i;
    }
    return -1;
}
int main(){
    int n;cin>>n;
    cin.ignore();
    map<string,vector<string>> mp;
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        int pos = tim(s,'-');
        string t1=s.substr(0,pos-1);
        string t2=s.substr(pos+2);
        mp[t1].push_back(t2);
        mp[t2].push_back(t1);
    }
    for(auto it:mp){
        sort(it.second.begin(),it.second.end());
        cout<<it.first<<" : ";
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i];
            if(i!=it.second.size()-1) cout<<", ";
        }
        cout<<endl;
    }
    
}