#include <iostream>
#include <cmath>
#include <algorithm>
#define maxn 1000001
using namespace std;
using ll=long long;
ll n, a[maxn], f[maxn][22], g[maxn][22];
//chu y ham nay rat can thiet tranh tle neu dung log2 thong thuong
ll log2_floor(unsigned long long n) 
{
    return n ? 63 - __builtin_clzll(n) : -1;
}

ll get_min(ll l, ll r) {
    ll k = log2_floor(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

// ll get_max(ll l, ll r) {
//     ll k = log2_floor(r - l + 1);
//     return max(g[l][k], g[r - (1 << k) + 1][k]);
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++) cin >> a[i], f[i][0] = g[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            //g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    long long cnt=0;
    ll t;
    scanf("%lld",&t);
    while (t--) {
        ll l, r;
        scanf("%lld%lld",&l,&r);l++,r++;
        cnt+=get_min(l, r);
    }
    printf("%lld",cnt);
    return 0;
}
