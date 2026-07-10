class Solution {
public:
    bool ispal(int i, int j, string& s, vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        while(j > i){
            if(s[j] != s[i]) return false;
            i++;
            j--;
        }
        return dp[i][j] = true;
    }

    vector<vector<string>> ans;
    vector<string> temp;

    void pp(int it, string& s, vector<vector<int>>& dp){
        if(it == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=it; i<s.size(); i++){
            if(dp[it][i] == 1 || ispal(it, i, s, dp)){
                temp.push_back(s.substr(it,i-it+1));
                pp(i+1, s, dp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        pp(0, s, dp);
        return ans;
    }
};
