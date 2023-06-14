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
    void init_set(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;

        vec.push_back(root->val);
        init_set(root->left, vec);
        init_set(root->right, vec);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        init_set(root, vec);
        int min_diff  = INT_MAX;

        sort(vec.begin(), vec.end());
        for(int i=1; i<vec.size(); ++i){
            min_diff = min(min_diff, vec[i]-vec[i-1]);
        }
        return min_diff;
    }
};