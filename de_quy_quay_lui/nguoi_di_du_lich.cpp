#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n, a[100][100];
int res = INT_MAX, sum = 0;
int visited[100], x[100];
vector<int> vt;
int cmin=1e9+7;

void ktao(){
    x[1] = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            cmin=min(cmin,a[i][j]);
        }
    }
    memset(visited, 0, sizeof(visited));
}

void Try(int i){
    for(int j = 2; j <= n; j++){
        if(visited[j] == 0){
            x[i] = j;
            sum += a[x[i - 1]][j];
            visited[j] = 1;
            if(i == n){
                if(res > sum + a[x[i]][1]){
                    vt.clear();
                    res = sum + a[x[i]][1];
                    vt.push_back(1);
                    for(int k = 2; k <= n; k++){
                        vt.push_back(x[k]);
                    }
                    vt.push_back(1);
                }
            }else if(sum+(n-i+1)*cmin<res) Try(i + 1);
            visited[j] = 0;
            sum -= a[x[i - 1]][j];
        }
    }
}

int main(){
    ktao();
    Try(2);
    for(int x : vt) cout << x << " ";
    cout << endl << res;
    return 0;
}
