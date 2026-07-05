class Solution {
public:
    void calc(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &t, int &tar, int sm){
        if(i == nums.size() || sm >= tar){
            if(sm == tar) ans.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        calc(i, nums, ans, t, tar, sm + nums[i]);
        t.pop_back();
        calc(i+1, nums, ans, t, tar, sm);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        calc(0, nums, ans, t, target, 0);
        return ans;
    }
};
