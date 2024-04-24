#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

bool cmp(const Edge & e1,const Edge & e2){
    return e1.w<e2.w;
}

const int MAX = 100005;
int n, m;
int p[MAX], r[MAX];

void makeSet(int u) {
    p[u] = u;
    r[u] = 0;
}

int findSet(int u) {
    return (p[u] == u) ? u : (p[u] = findSet(p[u]));
}

void unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u != v) {
        if (r[u] > r[v]) {
            p[v] = u;
        } else {
            p[u] = v;
            if (r[u] == r[v]) r[v]++;
        }
    }
}

int kruskal(const vector<Edge>& edges) {
    for (int i = 1; i <= n; ++i) {
        makeSet(i);
    }
    int mstWeight = 0;
    for (const Edge& e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            unionSet(e.u, e.v);
            mstWeight += e.w;
        }
    }
    return mstWeight;
}

int main() {
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    sort(edges.begin(), edges.end(),cmp);

    int mstWeight = kruskal(edges);
    cout << mstWeight << endl;

    return 0;
}
