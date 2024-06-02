// cho 1 day so a1,...an, va so nguyen b
// chi bang phep toan '+','-' tao ra nhieu nhat bao nhieu cach
// vd : 6 12 
// 3 2 7 5 2 3
// 3+2+7-5+2+3
// 3+2+7+5-2-3
// 3-2+7+5+2-3 
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int a[31];
int n, b;

void backTrack(int i, int sum) {
    if (i == n) {
        if (sum == b) {
            cnt++;
        }
        return;
    }

    backTrack(i + 1, sum + a[i]);
    backTrack(i + 1, sum - a[i]);
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    backTrack(1,a[0]);
    cout << cnt << endl;

    return 0;
}
