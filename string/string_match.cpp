#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt=0;
vector<int> prefixFunction(const string& P) {
    int m = P.length();
    vector<int> pi(m + 1);
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; ++q) {
        while (k > 0 && P[k] != P[q - 1]) {
            k = pi[k];
        }
        if (P[k] == P[q - 1]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

void KMPStringMatching(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();
    vector<int> pi = prefixFunction(P);
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == m) {
            cnt++;
            q = pi[q];
        }
    }
}

int main() {
    string T, P;
    getline(cin, T);
    getline(cin, P);

    KMPStringMatching(P, T);
	cout<<cnt;
    return 0;
}
