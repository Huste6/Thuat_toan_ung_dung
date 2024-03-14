#include<bits/stdc++.h>
using namespace std;

int n, s, t, u, v;
int a[1001][1001];
int d[1001][1001];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
bool ok = false;

void inp() {
    cin >> n >> s >> t >> u >> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    memset(d, -1, sizeof(d));
}

void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i, j});
    d[i][j] = 0;
    a[i][j] = 0; 
    while (!q.empty()) {
        pair<int,int> f = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int i1 = f.first + dx[k];
            int j1 = f.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1 && d[i1][j1] == -1) {
                a[i1][j1] = 0; 
                d[i1][j1] = d[f.first][f.second] + 1;
                q.push({i1, j1});
            } else if (i1 == u && j1 == v) { 
                ok = true;
                cout << d[i1][j1] << endl; 
                return;
            }
        }
    }
    if (!ok) cout << -1 << endl;
}

int main() {
    inp();
    bfs(s, t);
    return 0;
}
