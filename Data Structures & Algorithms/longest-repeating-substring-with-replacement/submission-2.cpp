class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int mx=0, m=0;
        unordered_map<char, int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            m = max(m, mp[s[r]]);
            if(r-l+1 - m <= k){
                mx = max(r-l+1, mx);
            }
            while(r-l+1 - m > k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return mx;
    }
};