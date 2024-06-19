#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[101][101];
string word;
bool check = false;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visited[101][101];

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> word;
    memset(visited, false, sizeof(visited));
}

void backtrack(int i, int j, int index) {
    if (index == word.size()) {
        check = true;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] == word[index]) {
            visited[i1][j1] = true;
            backtrack(i1, j1, index + 1);
            visited[i1][j1] = false;
        }
    }
}

int main() {
    inp();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == word[0]) {
                check = false; 
                backtrack(i, j, 1);
                if (check) {
                    cout << "YES" << endl;
                    return 0; 
                }
            }
        }
    }
    cout << "NO" << endl; 
    return 0;
}
// 3 4
// // A B C E
// // S F C S
// // A D E E
// // ABCCED