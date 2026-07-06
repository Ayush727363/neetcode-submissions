class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    unordered_set<int> st;
    
    void p(vector<int>& nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                p(nums);
                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        p(nums);
        return ans;
    }
};
