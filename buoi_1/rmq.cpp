#include <iostream>
#include <cmath>
#include <algorithm>
#define maxn 50004
using namespace std;

int n, a[maxn], f[maxn][22], g[maxn][22];
//chu y ham nay rat can thiet tranh tle neu dung log2 thong thuong
int log2_floor(unsigned long long n) 
{
    // Số bit 0 đứng đầu của 1 trừ đi số bit 0 đứng đầu của n.
    return n ? __builtin_clzll(1) - __builtin_clzll(n) : -1;
}

int get_min(int l, int r) {
    int k = log2_floor(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int get_max(int l, int r) {
    int k = log2_floor(r - l + 1);
    return max(g[l][k], g[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i][0] = g[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            //g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    long long cnt=0;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;l++,r++;
        cnt+=get_min(l, r);
    }
    cout<<cnt;
    return 0;
}
