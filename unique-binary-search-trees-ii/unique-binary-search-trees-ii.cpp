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
    vector<TreeNode*> solve(int s, int e) {
        vector<TreeNode*> ans;
        
        if(s > e) {
            ans.push_back(NULL);
            return ans;
        }

        for(int rt = s; rt <= e; ++rt) {
            vector<TreeNode*> leftSubTree = solve(s, rt-1);
            vector<TreeNode*> rightSubTree = solve(rt+1, e); 
                
            for(int j = 0; j < leftSubTree.size(); j++) {
                for(int k = 0; k < rightSubTree.size(); k++) {
                    TreeNode* root = new TreeNode(rt);   
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k]; 
                    ans.push_back(root); 
                }
            }
        }            
        return ans;
    }
    public:  
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};