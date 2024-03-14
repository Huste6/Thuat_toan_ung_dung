#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100; 

int a[MAX_N];
int n, k,sum=0,cnt=0; 
int res = 0;
map<int, int> mp;
vector<int> vt;
vector<int> kq;

void Start() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]] = i;
    }
}

void Try(int i, int pos) {
    for (int j = pos; j < n; ++j) {
        sum += a[j];
        cnt++;
        vt.push_back(a[j]);
        if (cnt == k) {
            bool valid = true;
            for (int k = 1; k < vt.size(); ++k) {
                if (mp[vt[k]] - mp[vt[k - 1]] >= 3) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if(res<sum){
                    kq.clear();
                    res=sum;
                    for(int f=0;f<k;f++){
                        kq.push_back(vt[f]);
                    }
                }
            }
        } else {
            Try(i + 1, j + 1);
        }
        cnt--;
        sum -= a[j];
        vt.erase(vt.begin() + j);
    }
}

int main() {
    Start();
    Try(0, 0);
    cout << res << endl;
    for(auto it:kq) cout<<it<<' ';
    cout<<endl;
    return 0;
}
