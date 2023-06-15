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
public:
    int maxLevelSum(TreeNode* root) {
        if(root == NULL) return 0;
        int cur_lvl = 0;

        int ans = cur_lvl;
        int max_lvl_sum = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvl = q.size();
            cur_lvl++;
            int lvl_sum = 0;
            for(int i=0; i<lvl; i++){
                TreeNode* node = q.front();
                q.pop();

                lvl_sum += node->val;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            if(lvl_sum > max_lvl_sum){
                max_lvl_sum = lvl_sum;
                ans = cur_lvl;
            }
        }
        return ans;
    }
};