#include <bits/stdc++.h>
using namespace std;

int n;
string x;
string s = "(){}[]";

bool check(string x) {
    stack<char> st;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
            st.push(x[i]);
        } else {
            if (st.empty())
                return false;
            char top = st.top();
            if ((x[i] == ')' && top == '(') || (x[i] == '}' && top == '{') || (x[i] == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

void Try(int i) {
    if (i == n) {
        if (check(x))
            cout << x << "\n";
        return;
    }
    for (int j = 0; j < s.size(); j++) {
        x += s[j];
        Try(i + 1);
        x.pop_back();
    }
}

int main() {
    cin >> n;
    Try(0);
    return 0;
}
