class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> mp;
        for(char c : s1) mp[c]++;
        int l = 0, r = 0;
        while(r < s2.size()) {
            mp[s2[r]]--;
            if(mp[s2[r]] == 0) mp.erase(s2[r]);
            if(r - l + 1 > s1.size()) {
                mp[s2[l]]++;
                if(mp[s2[l]] == 0) mp.erase(s2[l]);
                l++;
            }
            if(mp.empty() && r - l + 1 == s1.size())
                return true;

            r++;
        }
        return false;
    }
};