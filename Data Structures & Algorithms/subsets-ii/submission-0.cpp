class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    void s(int it, vector<int>&nums){
        ans.push_back(t);
        for(int i=it; i<nums.size(); i++){
            if(i > it && nums[i] == nums[i-1]) continue;
            t.push_back(nums[i]);
            s(i+1, nums);
            t.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        s(0, nums);
        return ans;
    }
};
