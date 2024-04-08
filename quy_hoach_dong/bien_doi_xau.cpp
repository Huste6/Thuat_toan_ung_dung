#include <bits/stdc++.h>
using namespace std;
int F[101][101];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    s1 = "0" + s1;
    s2 = "0" + s2;
    for (int i = 1; i <= n; i++) F[i][0] = i;
    for (int j = 1; j <= m; j++) F[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(s1[i]!=s2[j]) F[i][j] = min({F[i - 1][j], F[i][j - 1], F[i - 1][j - 1]}) + 1;
            else F[i][j]=F[i-1][j-1];
        }
    }
    cout << F[n][m];
}
