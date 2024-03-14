#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> canh;

int main(){
    int n;cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string s;getline(cin,s);
        stringstream ss(s);
        string so;
        while(ss >> so){
            //do thi co huong
            canh.push_back({i,stoi(so)});
        }
    }
    sort(begin(canh),end(canh));
    for(auto it:canh){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}