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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        int lvl = 1;
        q.push(root);

        while(!q.empty()){
            int p = lvl ? INT_MIN : INT_MAX;
            for(int i=q.size()-1; i>=0; --i){
                TreeNode* f = q.front();
                q.pop();
                if((f->val)%2 != lvl){
                    return false;
                }
                if(lvl){
                    if(f->val <= p) return false;
                    p = f->val;
                }
                else{
                    if(f->val >= p) return false;
                    p = f->val;
                }
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
            lvl = 1-lvl;
        }
        return true;
    }
};