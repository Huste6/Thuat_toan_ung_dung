#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
int res = 0;
int n, ans;
int x[22];

void inp() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> ans;
}

void backTrack(int u, int pos, int sum) {
    if (sum >= ans) {
        res = (res + 1) % MOD;
    }
    for (int i = pos; i < n; i++) {
        backTrack(u + 1, i + 1, sum + x[i]);
    }
}

int main() {
    inp();
    backTrack(0, 0, 0);
    cout << res << endl;
    return 0;
}