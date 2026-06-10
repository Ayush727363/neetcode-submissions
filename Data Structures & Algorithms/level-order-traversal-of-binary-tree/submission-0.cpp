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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int s = que.size();
            vector<int>level;
            while(s>0){
                TreeNode* t = que.front();
                que.pop();
                s--;
                level.push_back(t->val);
                if(t->left){
                    que.push(t->left);
                }
                if(t->right){
                    que.push(t->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};
