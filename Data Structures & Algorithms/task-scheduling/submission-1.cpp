class Solution {
    struct cmp{
        bool operator()(pair<char,int> &a, pair<char,int> &b){
            return a.second < b.second;
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for(char &i : tasks) mp[i - 'A']++;

        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        for(int i=0; i<26; i++)
            if(mp[i] != 0) pq.push({'A' + i , mp[i]});

        int c = 0;
        while(!pq.empty()){
            vector<pair<char,int>> temp;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    auto curr = pq.top();
                    pq.pop();
                    curr.second--;
                    if(curr.second > 0) temp.push_back(curr);
                }
                c++;
                if(temp.empty()) break;
            }
            for(auto &i : temp)
                pq.push(i);
        }
        return c;
    }
};
