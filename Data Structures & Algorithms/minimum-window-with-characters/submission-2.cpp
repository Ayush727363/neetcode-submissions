class Solution {
public:
    string minWindow(string s, string t) {
        int l=0, r=0;
        int len = 1e9;
        int start = 0;
        int req = t.size(); 
        unordered_map<char, int> mp;
        for(char i : t) mp[i]++;
        while(r<s.size()){
            if(mp[s[r]] > 0) req--;
            mp[s[r]]--;
            r++;
            while(req == 0){
                if(r-l < len){
                    len = r-l;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    req++;
                } 
                l++;
            }
        }
        return len == 1e9 ? "" : s.substr(start, len);
    }
};
