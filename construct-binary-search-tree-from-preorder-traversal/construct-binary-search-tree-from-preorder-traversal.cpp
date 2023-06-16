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
    TreeNode* solve(vector<int>& A, int s, int e){
        if(s > e){
            return NULL;
        }
        TreeNode* rt = new TreeNode(A[s]);
        int rightRoot = s+1;
        while(rightRoot < A.size() && A[rightRoot] < A[s]) ++rightRoot;
        rt->left = solve(A, s+1, rightRoot-1); 
        rt->right = solve(A, rightRoot, e);
        return rt;
    } 
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder, 0, preorder.size()-1);
    }
};