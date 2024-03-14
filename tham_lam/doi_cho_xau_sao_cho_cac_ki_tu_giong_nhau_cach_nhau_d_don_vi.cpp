#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool cmp(pair<char, int> a, pair<char, int> b) {
    return a.second > b.second;
}

int main() {
    int d;
    string s;
    cin >> d >> s;

    map<char, int> mp;
    for (char x : s)
        mp[x]++;

    vector<pair<char, int>> vt;
    for (auto it : mp)
        vt.push_back(it);

    sort(begin(vt), end(vt), cmp);

    string res = string(s.size(), '*');
    bool ok = true;

    for (int i = 0; i < vt.size(); i++) {
        int pos = i;
        while (res[pos] != '*')
            ++pos;
        for (int k = 0; k < vt[i].second; k++) {
            if (pos + k * d >= s.size()) {
                ok = false;
                break;
            }
            res[pos + k * d] = vt[i].first;
        }

        if (!ok) break;
    }

    if (!ok)
        cout << "-1";
    else
        cout << res;

    return 0;
}
