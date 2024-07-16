#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k, a[100], sum = 0, s;
int visited[100];
int x[100];

void Try(int i, int pos) {
    for (int j = pos; j < n; j++) {
        x[i] = a[j];
        sum += a[j];
        if (sum == s) {
            cout << "[";
            for (int f = 0; f <= i; f++) {
                cout << x[f] << " ";
            }
            cout << "] ";
        }else Try(i + 1, j + 1);
        sum -= a[j];
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    memset(visited, 0, sizeof(visited));
    if (s % k != 0)
        cout << 0;
    else {
        s = s / k;
        Try(0, 0);
    }
}
/*
#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100];
int x[100];
bool ok = false;
int s;
int cnt = 0;

void inp() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

void Try(int i, int pos, int sum) {
    if (cnt >= k) return;
    if (sum == s) {
        cnt++;
        if (cnt == k) {
            cout << 1;
            exit(0); 
        }
        return; 
    }
    for (int j = pos; j <= n; j++) {
        Try(i + 1, j + 1, sum + a[j]);
    }
}

int main() {
    inp();
    for (int i = 1; i <= n; i++) s += a[i];
    if (s % k != 0) cout << 0;
    else {
        s = s / k;
        Try(1, 1, 0);
        if (cnt < k) cout << 0;  // If condition not met, print 0
    }
    return 0;
}

*/