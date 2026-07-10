class Solution {
public:
    bool ispal(int i, int j, string& s){
        while(j > i){
            if(s[j] != s[i]) return false;
            i++;
            j--;
        }
        return true;
    }

    vector<vector<string>> ans;
    vector<string> temp;

    void pp(int it, string& s){
        if(it == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=it; i<s.size(); i++){
            if(ispal(it, i, s)){
                temp.push_back(s.substr(it,i-it+1));
                pp(i+1, s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        pp(0, s);
        return ans;
    }
};
