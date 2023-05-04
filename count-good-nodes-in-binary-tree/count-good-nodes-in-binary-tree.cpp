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
    int ans=0;
    void dfs(TreeNode* root, int mx_val){
        if(root == NULL) return;
        if(root->val >= mx_val) ans++;
        mx_val = max(mx_val, root->val);

        if(root->left) dfs(root->left, mx_val); 
        if(root->right) dfs(root->right, mx_val); 
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};