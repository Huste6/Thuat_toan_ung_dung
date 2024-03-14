#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s, s1 = "";
string x = "";
char a[100];
bool visited[100];
set<string> vt;

void inp() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        x += tolower(s[i]);
        x += toupper(s[i]);
        s1 += tolower(s[i]);
    }
    memset(visited, false, sizeof(visited));
}

bool check(char a[]) {
    string s2 = "";
    for (int i = 0; i < strlen(a); i++) {
        s2 += tolower(a[i]);
    }
    return s2 == s1;
}

void Try(int i) {
    if (i == s.size()) {
        if (check(a)) {
            vt.insert(string(a, a + i));
        }
        return;
    }
    for (int j = 0; j < x.size(); j++) {
        if (!visited[j]) {
            a[i] = x[j];
            visited[j] = true;
            Try(i + 1);
            visited[j] = false;
        }
    }
}

int main() {
    inp();
    Try(0);
    for (const string &str : vt) {
        cout << str << endl;
    }
    return 0;
}
