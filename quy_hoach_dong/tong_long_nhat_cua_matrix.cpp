#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 1;

int n;
int matrix[maxn][4];

void nhap() {
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 3; j++) cin >> matrix[i][j];
    }
}

int maxSum(int matrix[][4], int n) {
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    for(int j = 1; j <= 3; j++) dp[1][j] = matrix[0][j];

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            int maxPrev = -1;

            for(int k = 1; k <= 3; k++) {
                if(k != j) maxPrev = max(maxPrev, dp[i - 1][k]);
            }

            dp[i][j] = maxPrev + matrix[i - 1][j];
        }
    }

    for(int k = 1; k <= 3; k++) {
        ans = max(ans, dp[n][k]);
    }
    return ans;
}

int main() {
    cin >> n;
    nhap();
    cout << maxSum(matrix, n);
    return 0;
}
