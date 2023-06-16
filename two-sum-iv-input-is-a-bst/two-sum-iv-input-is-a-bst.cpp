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
    void solve(TreeNode* root, vector<int>& arr){
        if(root == NULL) return;
        solve(root->left, arr);
        arr.push_back(root->val);
        solve(root->right, arr);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        // Brute force -> find preorder -> apply 2 pointer
        vector<int> pre;
        solve(root, pre);

        int i= 0; int j = pre.size()-1;
        while(i < j){
            if(pre[i] + pre[j] == k) return true;
            if(pre[i] + pre[j] > k) --j;
            else ++i;
        }   
        return false;
    }
};