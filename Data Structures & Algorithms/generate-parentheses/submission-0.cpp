class Solution {
public:
    vector<string> ans;
    string s="";
    void gp(int a, int b){
        if(a == 0 && b == 0) {
            ans.push_back(s);
            return;
        }
        if(a>0){
            s.push_back('(');
            gp(a-1, b);
            s.pop_back();
        }
        if(a < b){
            s.push_back(')');
            gp(a, b-1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        gp(n, n);
        return ans;
    }
};
