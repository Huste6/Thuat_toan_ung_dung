#include<bits/stdc++.h>
using namespace std;
using ll=long long;

bool checkphonenumber(const string& sdt){
    return sdt.size() == 10;
}

int main(){
    string cau; cin >> cau;
    map<string,ll> call_from;
    map<string,ll> call_time;
    ll cnt = 0;
    bool ok = true;
    while(cau != "#"){
        if(cau == "call"){
            char sdt1[15], sdt2[15];
            int y1, mm1, d1, h1, m1, s1, h2, m2, s2;
            scanf("%s %s %d-%d-%d %d:%d:%d %d:%d:%d", sdt1, sdt2, &y1, &mm1, &d1, &h1, &m1, &s1, &h2, &m2, &s2);
            string str_sdt1(sdt1), str_sdt2(sdt2);
            if(!checkphonenumber(str_sdt1) || !checkphonenumber(str_sdt2)) ok = false;
            cnt++;
            call_from[str_sdt1]++;
            call_time[str_sdt1] += (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
        }
        cin >> cau;
    }
    string cau_1; cin >> cau_1;
    while(cau_1 != "#"){
        if(cau_1 == "?check_phone_number"){
            cout << (ok ? "1" : "-1") << endl;
        }else if(cau_1 == "?number_calls_from"){
            string sdt; cin >> sdt;
            cout << call_from[sdt] << endl;
        }else if(cau_1 == "?number_total_calls"){
            cout << cnt << endl;
        }else if(cau_1 == "?count_time_calls_from"){
            string sdt; cin >> sdt;
            cout << call_time[sdt] << endl;
        }
        cin >> cau_1;
    }
}
