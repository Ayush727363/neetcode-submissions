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

    TreeNode* dfs(vector<int>& preorder, int pl, int pr, unordered_map<int,int>& mp, int il, int ir){
        
        if(pl > pr || il > ir) return NULL;

        TreeNode* root = new TreeNode(preorder[pl]);

        int inroot = mp[root->val];
        int lnums = inroot - il;

        root->left = dfs(preorder, pl+1, pl+lnums, mp, il, inroot-1);
        root->right = dfs(preorder, pl+1+lnums, pr, mp, inroot+1, ir);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return dfs(preorder, 0, preorder.size()-1, mp, 0, inorder.size()-1);
    }
};
