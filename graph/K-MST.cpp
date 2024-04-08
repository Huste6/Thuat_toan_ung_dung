#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Max = 50;

struct Node {
    int u, v, w;
    Node(int ui, int vi, int wi) {
        this->u = ui;
        this->v = vi;
        this->w = wi;
    }
};

int n, m, k;
vector<Node> ListNode;
int cmin = 1e9 + 7;
int x[Max];
bool visited[Max];
int tong_trong = 0;
int min_w = 1e9;

// make dsu
ll parent[Max], sz[Max];

void ktao() {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool unionSets(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false; 
    if(sz[u] < sz[v]) {
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
//finish dsu

void inp() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ListNode.push_back(Node(u, v, w));
        cmin = min(cmin, w);
    }
    memset(visited, false, sizeof(visited));
}

bool check(int a, int i) {
    if(visited[i]) return false;
    ktao(); // Thiết lập lại cấu trúc dữ liệu disjoint-set cho lần lặp này
    for(int j = 1; j < a; j++) {
        int pa = find(ListNode[x[j]].u);
        int pb = find(ListNode[x[j]].v);
        bool check = unionSets(pa, pb);
        if(!check) return false;
    }
    return true;
}

void Try(int a) {
    for(int i = 0; i < m; i++) {
        if(check(a, i)) {
            visited[i] = true;
            x[a] = i;
            tong_trong += ListNode[i].w;
            if(a == k) {
                min_w = min(min_w, tong_trong);
            }
            else if(tong_trong + (k - a) * cmin < min_w) Try(a + 1);
            tong_trong -= ListNode[i].w;
            visited[i] = false;
        }
    }
}

int main() {
    inp();
    Try(1);
    if(min_w == 1e9) cout << -1 << endl;
    else cout << min_w << endl;
    return 0;
}
