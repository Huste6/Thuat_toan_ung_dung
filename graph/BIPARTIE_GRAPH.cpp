#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1001]; 
bool visited[1001];

void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y); 
        ke[y].push_back(x); 
    }
    memset(visited, false, sizeof(visited));
}

bool isBipartite(int n, vector<int> adj[]) { 
    vector<int> color(n, -1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            q.push({i, 0});
            color[i] = 0;
            visited[i] = true;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for (int k : ke[x]) { 
                    if (color[k] == -1 && !visited[k]) {
                        if (y == 0)
                            color[k] = 1;
                        else if (y == 1)
                            color[k] = 0;
                        visited[k] = true;
                        q.push({k, color[k]});
                    }
                    if (color[k] == y)
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    nhap();
    if (isBipartite(n, ke) == true) 
        cout << 1;
    else
        cout << 0;
    return 0;
}
