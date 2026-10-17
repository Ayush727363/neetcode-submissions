class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l =0, r=0;
        int mx=0, m=0;
        while(r<n){
            mp[s[r]-'A']++;
            m = max(m, mp[s[r]-'A']);
            if((r-l+1)-m <= k){
                mx = max(r-l+1, mx);
            }
            while((r-l+1)-m > k){
                mp[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return mx;
    }
};
