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
    bool solve(TreeNode* root, set<int>& st, int k){
        if(root == NULL) return false;

        if(solve(root->left, st, k)) return true;
        
        if(st.find(root->val) != st.end()) return true;
        st.insert(k - root->val);
        
        return solve(root->right, st, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        // Brute force -> find preorder -> apply 2 pointer
        // vector<int> pre;
        set<int> vals;
        return solve(root, vals, k);

        // int i= 0; int j = pre.size()-1;
        // while(i < j){
        //     if(pre[i] + pre[j] == k) return true;
        //     if(pre[i] + pre[j] > k) --j;
        //     else ++i;
        // }   
        // return false;
    }
};