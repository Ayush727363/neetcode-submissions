class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ans;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] < nums[(m+1)%n] && nums[m] < nums[((m-1)%n + n)%n]){
                ans = m;
                break;
            }
            else if(nums[m] < nums[r]) r = m-1;
            else l = m+1;
        }
        return nums[ans];
    }
};
