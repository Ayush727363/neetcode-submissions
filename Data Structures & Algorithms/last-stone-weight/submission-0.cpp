class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) pq.push(i);

        while(!pq.empty()){
            int h = pq.top();
            pq.pop();
            if(pq.empty()) return h;
            int l = pq.top();
            pq.pop();
            pq.push(h-l);
        }
    }
};
