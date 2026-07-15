class Solution {
public:
    bool f(int i, vector<int>& nums){
        if(i == nums.size()-1) return true;
        if(nums[i] == 0) return false;

        int j=nums[i];
        if(i+j > nums.size()-1) j = nums.size()-1 - i;
        for(j; j>0; j--){
            if(f(i+j, nums)) return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return f(0, nums);
    }
};
