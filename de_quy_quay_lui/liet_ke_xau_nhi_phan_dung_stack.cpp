#include <bits/stdc++.h>
using namespace std;
bool check(string x,int k) {
    int cnt1 = 1;int tmp=0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '1' && x[i-1]=='1') {
            cnt1++;
            tmp=max(tmp,cnt1);
        } else {
            cnt1 = 1;
        }
        if(cnt1>k) return false;
    }
    return tmp==k;
}

void solve(int n,int k) {
    stack<string> st;
    st.push("");
    while (!st.empty()) {
        string currstr = st.top();
        st.pop();
        if (currstr.size() == n) {
            if (check(currstr,k)) {
                cout << currstr << endl;
            }
        } else {
            st.push(currstr + '1');
            st.push(currstr + '0');
        }
    }
}

int main() {
    int n,k;
    cin >> n>>k;
    solve(n,k);
    return 0;
}