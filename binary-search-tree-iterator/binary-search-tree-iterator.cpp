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
class BSTIterator {
    vector<int> in_ord;
    void inOrdTrav(TreeNode* root){
        if(root == NULL) return;
        if(root->left) inOrdTrav(root->left);
        in_ord.push_back(root->val);
        if(root->right) inOrdTrav(root->right);
    }
    int idx;
public:
    BSTIterator(TreeNode* root) {
        in_ord.clear();
        inOrdTrav(root);
        idx = 0;
    }
    
    int next() {
        return in_ord[idx++];
    }
    
    bool hasNext() {
        return idx < in_ord.size();        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */