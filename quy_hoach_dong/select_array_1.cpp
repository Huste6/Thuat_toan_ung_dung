#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 1001;

int F[MAXN][MAXM];

int main() {
    int n, m;
    cin >> n >> m;

    int a[n+1];
    int res = 0;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    if(a[1] != 0)
        F[1][a[1]] = 1;
    else {
        for(int j = 1; j <= m; j++)
            F[1][j] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == 0)
                F[i][j] = (F[i-1][j-1] + F[i-1][j] + F[i-1][j+1]) % 1000000007;
            else
                F[i][a[i]] = (F[i-1][a[i]-1] + F[i-1][a[i]] + F[i-1][a[i]+1]) % 1000000007;
        }
    }

    for(int j = 1; j <= m; j++)
        res = (res + F[n][j]) % 1000000007;

    cout << res << endl;

    return 0;
}
