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
    int pathSumFrmHere(TreeNode* root, long long target){
        if(root == NULL) return 0;

        int ans = 0;
        if((root->val)*1ll == target) ++ans;
        long long newTarget = target - (root->val)*1ll;
        ans += pathSumFrmHere(root->left, newTarget);
        ans += pathSumFrmHere(root->right, newTarget);

        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathSumFrmHere(root, targetSum);
    }
};