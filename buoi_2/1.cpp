#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int max_n = 20;
const int max_k = 10;
int n, K, q;
int d[11];
int c[31][31];
int y[max_n]; // y[k] is the first customer in route k
int x[max_n]; // x[v] is the next point after v
bool visited[max_n];
int load[max_n]; // load[k] keeps track of the cargo load of customers on route k
int segment; // number of points on routes of all vehicles
int cmin = 1e9 + 1; // minimum distance
int distance_curr = 0;

void nhap() {
    cin >> n >> K >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
}

bool checkX(int v, int u, int k) {
    if (v == 0) return true;
    if (visited[v] && v != 0) return false;
    if (load[k] + d[v] > q) return false;
    return true;
}

void TryX(int u, int k) { // Try all values for x[u] on route k
    for (int v = 0; v <= n; v++) {
        if (checkX(v, u, k)) {
            x[u] = v;
            visited[v] = true;
            load[k] += d[v];
            segment += 1;
            distance_curr += c[x[u - 1]][x[u]];
            if (v == 0) {
                if (k == K) {
                    if (segment == n + K) {
                        if (cmin > distance_curr) {
                            cmin=distance_curr;
                        }
                    }
                } else {
                    TryX(y[k + 1], k + 1); 
                }
            } else {
                TryX(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            segment -= 1;
            distance_curr -= c[x[u - 1]][x[u]];
        }
    }
}

bool checkY(int v, int k) {
    if (v == 0) return true;
    if (visited[v]) return false;
    if (load[k] + d[v] > q) return false;
    return true;
}

void TryY(int k) { // Try the first values of y[k]: y[1]<y[2]<....y[k]
    for (int v = y[k - 1] + 1; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            visited[v] = true;
            load[k] += d[v];
            segment += 1;
            distance_curr += c[y[k - 1]][y[k]];
            if (k == K) {
                TryX(y[1], 1);
            } else {
                TryY(k + 1);
            }
            visited[v] = false;
            load[k] -= d[v];
            segment -= 1;
            distance_curr -= c[y[k - 1]][y[k]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    TryY(0);
    cout<<cmin;
    return 0;
}
