#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;cin>>s;
    map<char,int> mp;
    set<char> se;
    for(char x:s){
        mp[x]++;
        se.insert(x);
    }
    char res;int pos=0;
    for(auto it:mp){
        if(it.second > pos){
            pos=it.second;
            res=(char)it.first;
        }
    }
    cout<<res<<' '<<pos<<endl;
    pos=0;
    for(auto it:mp){
        if(it.second < pos){
            pos=it.second;
            res=(char)it.first;
        }
    }
    cout<<res<<' '<<pos<<endl;
    cout<<se.size()<<endl;
    return 0;
}