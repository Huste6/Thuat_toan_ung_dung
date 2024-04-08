#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> dialpad;
    vector<string> tmp_1;

    Solution() {
        dialpad['2'] = "abc";
        dialpad['3'] = "def";
        dialpad['4'] = "ghi";
        dialpad['5'] = "jkl";
        dialpad['6'] = "mno";
        dialpad['7'] = "pqrs";
        dialpad['8'] = "tuv";
        dialpad['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        Try(0, digits, "");
        return tmp_1;
    }

private:
    void Try(int i, const string& s, string tmp) {
        if(i >= s.size()) {
            tmp_1.push_back(tmp);
            return;
        }
        char ch = s[i];
        string str = dialpad[ch];
        for(int j = 0; j < str.size(); j++) {
            tmp += str[j];
            Try(i + 1, s, tmp);
            tmp.pop_back();
        }
    }
};
