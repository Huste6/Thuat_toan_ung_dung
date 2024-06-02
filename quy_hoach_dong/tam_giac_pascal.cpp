#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }

    for (int j = 2; j <= n; ++j) {
        for (int i = 2; i <= j; ++i) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= j; ++i) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
