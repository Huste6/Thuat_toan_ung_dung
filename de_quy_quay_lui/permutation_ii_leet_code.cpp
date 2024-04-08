class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        this->n = nums.size();
        map<int,int> mp;
        vector<int> path;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        Try(0, nums, mp, path, ans); 
        return ans;
    }
private:
    int n;
    void Try(int i, vector<int>& nums, map<int,int>& mp, vector<int>& path, vector<vector<int>>& ans) { 
        if(i == n) {
            ans.push_back(path);
            return;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->second == 0) continue;
            it->second--;
            path.push_back(it->first);
            Try(i + 1, nums, mp, path, ans);
            path.pop_back();
            it->second++;
        }
    }
};
