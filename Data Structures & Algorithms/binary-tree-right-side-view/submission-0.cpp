/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void rv(TreeNode* root, vector<vector<int>>& levels){
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int s = que.size();
            vector<int> level;
            while(s > 0){
                TreeNode* t = que.front();
                que.pop();
                level.push_back(t->val);
                s--;
                if(t->left) que.push(t->left); 
                if(t->right) que.push(t->right); 
            }
            levels.push_back(level);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> levels;
        rv(root, levels);
        vector<int> ans;
        for(int i =0; i<levels.size(); i++){
            ans.push_back(levels[i][levels[i].size()-1]);
        }
        return ans;
    }
};
