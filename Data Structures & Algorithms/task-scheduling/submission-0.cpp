class Solution {
    struct cmp{
        bool operator()(pair<char,int> &a, pair<char,int> &b){
            return a.second < b.second;
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        int t = tasks.size();
        for(char &i : tasks) mp[i - 'A']++;

        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        for(int i=0; i<26; i++)
            if(mp[i] != 0) pq.push({'A' + i , mp[i]});

        int c = 0;
        while(!pq.empty() && t>0){
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    mp[pq.top().first - 'A']--;
                    pq.pop();
                    t--;  
                }
                c++;
                if(t == 0) break;
            }
            for(int i=0; i<26; i++)
                if(mp[i] != 0) pq.push({'A' + i , mp[i]});
        }
        return c;
    }
};
