class Solution {
public:
    vector<vector<int>> ans;
    void swap(int i, int j, vector<int>& nums){
        int t = nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }

    void f(int it, vector<int>& nums){
        if(it == nums.size()) ans.push_back(nums);
        for(int i = it; i<nums.size(); i++){
            swap(it, i, nums);
            f(it+1, nums);
            swap(it, i, nums);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        f(0, nums);
        return ans;
    }
};
