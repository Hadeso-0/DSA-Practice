/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* rt, map<TreeNode*, TreeNode*>& parent){
        if(rt == NULL) return;
        if(rt->left){
            parent[rt->left] = rt;
            dfs(rt->left, parent);
        }
        if(rt->right){
            parent[rt->right] = rt;
            dfs(rt->right, parent);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent;
        dfs(root, parent);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);

        while((k > 0) && (!q.empty())){
            for(int i=q.size()-1; i>=0; --i){
                TreeNode* p = q.front(); q.pop();
                if(p->left && (vis.find(p->left)==vis.end())){
                    q.push(p->left);
                    vis.insert(p->left);
                }
                if(p->right && (vis.find(p->right)==vis.end())){
                    q.push(p->right);
                    vis.insert(p->right);
                }
                if((parent.find(p) != parent.end()) && (vis.find(parent[p])==vis.end())){
                    q.push(parent[p]);
                    vis.insert(parent[p]);
                }
            }
            --k;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back((q.front())->val);
            q.pop();
        }
        return ans;
    }
};