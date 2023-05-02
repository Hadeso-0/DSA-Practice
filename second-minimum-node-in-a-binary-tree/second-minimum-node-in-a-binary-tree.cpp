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
    set<int> ans;
    void inOrd(TreeNode* root){
        if(root == NULL) return;
        inOrd(root->left);
        ans.insert(root->val);
        inOrd(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        inOrd(root);
        if(ans.size() <= 1) return -1;
        else{
            return *(++ans.begin());
        }
    }
};