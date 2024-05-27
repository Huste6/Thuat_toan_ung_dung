#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Khởi tạo giá trị ban đầu cho dp
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 1e6;
        }
    }
    dp[1][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i][j] != 0) {
                if (i == 1) {
                    dp[i][j] = min(dp[i][j], a[i][j] + dp[i][j - 1]);
                } else if (j == 1) {
                    dp[i][j] = min(dp[i][j], a[i][j] + dp[i - 1][j]);
                } else {
                    dp[i][j] = min({dp[i][j], a[i][j] + dp[i - 1][j], a[i][j] + dp[i][j - 1], a[i][j] + dp[i - 1][j - 1]});
                }
            }
            dp[i][j] %= MOD;
        }
    }

    if (dp[n][m] == 1e6) {
        cout << -1 << endl;
    } else {
        cout << dp[n][m] << endl;
    }

    return 0;
}

// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 0 0 0 0 
// 6 7 0 5 4 3

// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 9 0 29 0 
// 6 7 0 5 4 3