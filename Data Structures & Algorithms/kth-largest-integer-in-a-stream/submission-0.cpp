class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > s) pq.pop();
        return pq.top();
    }
};
