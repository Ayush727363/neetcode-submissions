class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first*a.first + a.second*a.second < 
                   b.first*b.first + b.second*b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, cmp>pq;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0], points[i][1]});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
