#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 21;
const int MAXM = 41;

bool isIsomorphic(int graph1[MAXN][MAXN], int graph2[MAXN][MAXN], int n1, int m1, int n2, int m2) {
    if (n1 != n2 || m1 != m2)
        return false;
    vector<int> deg1(n1, 0), deg2(n2, 0);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n1; ++j) {
            deg1[i] += graph1[i][j];
            deg2[i] += graph2[i][j];
        }
    }
    sort(deg1.begin(), deg1.end());
    sort(deg2.begin(), deg2.end());
    return deg1 == deg2;
}

int main() {
    int n1, m1;
    cin >> n1 >> m1;

    int graph1[MAXN][MAXN] = {0};
    int graph2[MAXN][MAXN] = {0};
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        graph1[u - 1][v - 1] = graph1[v - 1][u - 1] = 1; 
    }

    int n2, m2;
    cin >> n2 >> m2;

    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        graph2[u - 1][v - 1] = graph2[v - 1][u - 1] = 1;
    }

    if (isIsomorphic(graph1, graph2, n1, m1, n2, m2))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
