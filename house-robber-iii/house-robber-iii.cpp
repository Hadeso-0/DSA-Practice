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
    pair<int,int> solve(TreeNode* root){
        if(root == NULL) return {0, 0};

        pair<int,int> lft = solve(root->left);  
        pair<int,int> rgt = solve(root->right);
        
        pair<int,int> ans;
        
        // include this val
        ans.first = root->val + lft.second + rgt.second;
        
        // exclude this val
        int v1 = lft.first + rgt.first;
        int v2 = lft.first + rgt.second;
        int v3 = lft.second + rgt.first;
        int v4 = lft.second + rgt.second;
        ans.second = max(v1, max(v2, max(v3, v4)));

        return ans;
    }
public:
    int rob(TreeNode* root) {
        // unordered_map<TreeNode*, pair<int, int>> dp;
        // pair<int,int> init_val = {-1,-1};
        // init_map(root, dp, init_val);
        
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);        
    }
};