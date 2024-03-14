#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e5 + 2;
const ll oo = 1e18;
ll n, q;
ll a[maxN], t[4 * maxN];

void build(ll v, ll l, ll r) {
    if (l == r) {
        t[v] = a[l];
    } else {
        ll m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

ll getmax(ll id, ll l, ll r, ll u, ll v) {
    if (l > v || r < u) return -oo;
    if (l >= u && r <= v) return t[id];
    ll mid = (l + r) / 2;
    return max(getmax(id * 2, l, mid, u, v), getmax(id * 2 + 1, mid + 1, r, u, v));
}

void update(ll id, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        t[id] = val;
    } else {
        ll mid = (l + r) / 2;
        if (pos <= mid) update(2 * id, l, mid, pos, val);
        else update(2 * id + 1, mid + 1, r, pos, val);
        t[id] = max(t[2 * id], t[2 * id + 1]);
    }
}

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--) { 
        string s;
        int x, y;
        cin >> s >> x >> y;
        if (s.compare("get-max") == 0) {
            cout << getmax(1, 1, n, x, y) << endl;
        } else if (s.compare("update") == 0) {
            update(1, 1, n, x, y);
        }
    }
}

int main() {
    nhap();
    return 0;
}
