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
    int solve(TreeNode* root, bool flg){
        if(root == NULL) return 0;
        if(flg && root->left == NULL && root->right==NULL){
            return root->val; // left leaf
        }
        if(root->left == NULL && root->right==NULL){
            return 0; // right leaf
        } 

        int lft = solve(root->left, 1);
        int rgt = solve(root->right, 0);
        return lft + rgt;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
          return solve(root , 0);
    }
};