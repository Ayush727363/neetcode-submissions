class Solution {
public:
    vector<string> ans;
    string temp = "";

    void f(int it, string& dig, vector<string>& mp){
        if(it == dig.size()){
            ans.push_back(temp);
            return;
        }
        for(char c : mp[dig[it] - '2']){
            temp.push_back(c);
            f(it+1, dig, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> mp = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        f(0, digits, mp);
        return ans;
    }
};
