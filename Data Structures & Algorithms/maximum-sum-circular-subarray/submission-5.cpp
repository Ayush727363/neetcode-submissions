class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int mn = nums[0];
        int sm = nums[0];
        int tsum =nums[0];
        int mx = nums[0];
        int smm = nums[0];
        for(int i=1; i<nums.size(); i++){
            tsum+=nums[i];
            sm = min(sm+nums[i], nums[i]);
            mn = min(mn, sm);

            smm = max(smm+nums[i],nums[i]);
            mx=max(mx, smm);
        }
        if(tsum - mn > 0) return max(mx, tsum - mn);
        return mx;
    }
};