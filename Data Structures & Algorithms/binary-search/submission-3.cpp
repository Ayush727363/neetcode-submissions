class Solution {
public:

    int srh(int l, int r, int t, vector<int>& nums){
        if(l > r) return -1;

        int mid = (l+r)/2;
        if(nums[mid] == t) return mid;
        if(nums[mid] < t) return srh(mid+1, r, t, nums);
        return srh(l, mid-1, t, nums);
    }

    int search(vector<int>& nums, int target) {
        return srh(0, nums.size()-1, target, nums);
    }
};
