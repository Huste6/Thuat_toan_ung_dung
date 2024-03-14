#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll S;
int a[100];
ll cnt = 0;
int x[100];

void Try(int sum, int i, int last_index) {
    
    if (i == m) {
        if (sum <= S){
            cnt++; // Đếm số lượng dãy con hợp lệ
            /*
            for(int k=0; k<i; k++){ // In ra các phần tử của dãy con
                cout << x[k] << " ";
            }
            cout << endl;*/
        }
        return;
    }
    for (int j = last_index + 1; j < n; j++) {
        if (sum + a[j] <= S && (!i || j - x[i-1] >= 2)) { // Kiểm tra khoảng cách và tổng
            x[i] = j; 
            Try(sum + a[j], i + 1, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> S;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Try(0, 0, -1);
    cout << cnt%(static_cast<long long>(1e9) + 7)<< endl; 
    return 0;
}
