#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//intput:
//10 6 5
//2 10 1 5 9
//minh hoa
//1 2 3 4 5 6 7 8 9 10
//x x     x       x x
//cai can sua la cai 5 la du 6 den lien tiep ko hong
int main(){
    int n, k, b;
    cin >> n >> k >> b;
    set<int> v; 
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        v.insert(x);
    }
    ll so_den_hong = 0;
    for (int i = 0; i < k; i++) {
        if (v.count(i) != 0) 
            so_den_hong++;
    }
    ll res = so_den_hong;
    for (int i = k; i < n; i++) {
        if (v.count(i - k) != 0)
            so_den_hong--;
        if (v.count(i) != 0)
            so_den_hong++;
        if (res > so_den_hong)
            res = so_den_hong;
    }
    cout << res << endl;
    return 0;
}