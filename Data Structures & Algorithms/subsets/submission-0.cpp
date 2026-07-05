class Solution {
public:
    void calc(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &t){
        if(i == nums.size()){
            ans.push_back(t);
            return;
        }
        t.push_back(nums[i]);
        calc(i+1, nums, ans, t);
        t.pop_back();
        calc(i+1, nums, ans, t);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        calc(0, nums, ans, t);
        return ans;
    }
};
