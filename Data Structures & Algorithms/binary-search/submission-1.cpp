class Solution {
public:

    int srh(int l, int r, int t, vector<int>& nums){

        int mid = (r+l)/2;
        if(nums[mid] == t) return mid;
        if(r <= l) return -1;
        else if(nums[mid] < t) return srh(mid+1, r, t, nums);
        else return srh(l, mid, t, nums);
    }

    int search(vector<int>& nums, int target) {
        return srh(0, nums.size()-1, target, nums);
    }
};
