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
    int solve(TreeNode* root, bool canInclude, unordered_map<TreeNode*, pair<int,int>>& dp){
        if(root == NULL) return 0;

        if(canInclude) {
            if(dp[root].first != -1) return dp[root].first;
        }
        else{
            if(dp[root].second != -1) return dp[root].second;
        }

        int incl = 0;
        int excl = solve(root->left, 1, dp) + solve(root->right, 1, dp);
        // if can include -> I can include or exclude
        if(canInclude){
            incl = root->val + solve(root->left, 0, dp) + solve(root->right, 0, dp);
            return dp[root].first = max(incl, excl);
        }

        // if cannot include -> I can only exclude
        return dp[root].second = excl;
    }
    void init_map(TreeNode* root, unordered_map<TreeNode*, pair<int,int>>& dp){
        if(root == NULL) return;
        dp[root] = {-1,-1};
        init_map(root->left, dp);
        init_map(root->right, dp);
    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> dp;
        init_map(root, dp);
        return solve(root, 1, dp);        
    }
};