class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return{};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int s = que.size();
            for(int i =0; i<s; i++){
                TreeNode* t = que.front();
                que.pop();
                if(i == s-1) ans.push_back(t->val);
                if(t->left) que.push(t->left); 
                if(t->right) que.push(t->right); 
            }
        }
        return ans;
    }
};
