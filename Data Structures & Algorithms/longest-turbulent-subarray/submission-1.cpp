class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1, len=1;
        int prev = 0;
        for(int i=1; i<arr.size(); i++){
            int curr=0;
            if(arr[i-1] < arr[i]) curr = 1;
            else if(arr[i-1] > arr[i]) curr = -1;

            if(curr == 0) len = 1;
            else if(curr == -prev) len++;
            else len = 2;

            prev = curr;
            ans = max(ans, len);
        }
        return ans;
    }
};