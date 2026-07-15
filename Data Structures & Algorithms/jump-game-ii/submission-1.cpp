class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int l=0, r=0;
        int jump=0;
        while(r < nums.size()-1){
            int mx=0;
            for(int i=l; i<=r; i++){
                mx = max(mx, i + nums[i]);
            }
            l = r+1;
            r = mx;
            jump++;
        }
        return jump;
    }
};
