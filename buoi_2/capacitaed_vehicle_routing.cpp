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
int min_of_c=1e9;
int nbr;
int s=0;

void nhap() {
    cin >> n >> K >> q;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if(i!=j) min_of_c=min(min_of_c,c[i][j]);
        }
    }
    memset(visited, false, sizeof(visited));
    y[0]=0;
}

bool checkX(int v, int u, int k) {
    if (visited[v] && v > 0) return false;
    if (load[k] + d[v] > q) return false;
    return true;
}


void TryX(int u, int k) { // Try all values for x[u] on route k
    if(u==0){
        if(k<K) TryX(y[k+1],k+1);
        return;
    }
    for (int v = 0; v <= n; v++) {
        if (checkX(v, u, k)) {
            x[u] = v;
            visited[v] = true;
            load[k] += d[v];
            segment += 1;
            distance_curr += c[u][v];
            if (v == 0) {
                if (k == K) {
                    if (segment == n + nbr) {
                        if (cmin > distance_curr) {
                            cmin=distance_curr;
                        }
                    }
                } else {
                    if(distance_curr+(n+nbr-segment)*min_of_c < cmin) TryX(y[k + 1], k + 1); 
                }
            } else {
                if(distance_curr+(n+nbr-segment)*min_of_c< cmin) TryX(v, k);
            }
            visited[v] = false;
            load[k] -= d[v];
            segment -= 1;
            distance_curr -= c[u][v];
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
    if(y[k-1]>0) s=y[k-1]+1;
    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            visited[v] = true;
            load[k] += d[v];
            if(v>0) segment += 1;
            distance_curr += c[0][v];
            if (k == K) {
                nbr=segment;
                TryX(y[1], 1);
            } else {
                TryY(k + 1);
            }
            visited[v] = false;
            load[k] -= d[v];
            if(v>0) segment -= 1;
            distance_curr -= c[0][v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    nhap();
    TryY(1);
    cout<<cmin;
    return 0;
}
