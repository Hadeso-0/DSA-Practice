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
    unordered_map<TreeNode*, TreeNode*> par;
    void dfs(TreeNode* node){
        if(node == NULL) return;
        if(node->left){
            par[node->left] = node;
            dfs(node->left);
        }
        if(node->right){
            par[node->right] = node;
            dfs(node->right);
        }
    }
    TreeNode* findNode(TreeNode* node, int val){
        if(node == NULL) return NULL;
        if(node->val == val) return node;

        TreeNode* lft = findNode(node->left, val);
        if(lft) return lft;

        return findNode(node->right, val);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        TreeNode* burnStart = findNode(root, start);
        
        int time = -1;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> q;
        q.push(burnStart);
        vis.insert(burnStart);

        while(!q.empty()){
            ++time;
            for(int i=q.size()-1; i>=0; --i){
                TreeNode* burnThis = q.front(); q.pop();
                // cout<<burnThis->val<<" ";
                if(burnThis->left != NULL){
                    if(vis.find(burnThis->left) == vis.end()){
                        q.push(burnThis->left);
                        vis.insert(burnThis->left);
                    }
                }
                if(burnThis->right != NULL){
                    if(vis.find(burnThis->right) == vis.end()){
                        q.push(burnThis->right);
                        vis.insert(burnThis->right);
                    }
                }
                if(par.find(burnThis) != par.end()){
                    if(vis.find(par[burnThis]) == vis.end()){
                        q.push(par[burnThis]);
                        vis.insert(par[burnThis]);
                    }
                }
            }
            // cout<<endl;
        }
        return time;
    }
};