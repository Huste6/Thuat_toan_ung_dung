//pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+arr[i][j]
//tinh tong hang tu a->A va cot b->B
//tong=pre[A][B]-pre[a-1][B]-pre[A][b-1]+pre[a-1][b-1]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pre[1001][1001];
ll a[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
    }
    ll q;
    scanf("%lld", &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%lld\n", pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1]);
    }
    return 0;
}
