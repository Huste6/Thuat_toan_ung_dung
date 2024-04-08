#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod=1e9+7;
/*
ma tran mu n len thi se thu duoc ma tran 
1 1                     f[n+1] f[n]   
1 0                     f[n]   f[n-1]
*/
struct matrix {
    ll f[2][2];
};

matrix operator*(matrix a, matrix b) {
    matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.f[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.f[i][j] = (c.f[i][j] + a.f[i][k] * b.f[k][j]) % mod;
            }
        }
    }
    return c;
}

matrix powMod(matrix a, ll n) {
    if (n == 1) return a;
    matrix x = powMod(a, n / 2);
    x = x * x;
    if (n % 2) x = x * a;
    return x;
}

int main() {
    matrix a;
    a.f[0][0] = a.f[1][0] = a.f[0][1] = 1;
    a.f[1][1] = 0;
    ll n;
    cin >> n;
    matrix b = powMod(a, n);
    cout << b.f[0][1]<<" "<<b.f[1][0]<< endl;
    return 0;
}