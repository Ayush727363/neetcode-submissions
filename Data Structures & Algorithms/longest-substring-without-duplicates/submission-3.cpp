class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<=1) return n;
        unordered_map<char, int> mp;
        int l=0, r=0;
        int mx = 0;
        while(r<n){
            if(!mp.count(s[r])){
                mp[s[r]]++;
                r++;
            }
            else{
                while(mp.count(s[r]) && l<=r){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                }
            }
            mx = max(mx, r-l);
        }
        return mx;
    }
};
