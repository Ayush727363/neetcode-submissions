class TimeMap {
    unordered_map<string, vector<pair<string,int>>> mp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int t) {
        string s;
        vector<pair<string,int>> v = mp[key];
        int l = 0, r = v.size()-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(v[m].second <= t){
                s = v[m].first;
                l = m+1;
            }
            else r = m-1;
        }
        return s;
    }
};
