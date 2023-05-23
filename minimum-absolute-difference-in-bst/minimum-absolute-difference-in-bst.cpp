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
    void init_set(TreeNode* root, set<int>& st){
        if(root == NULL) return;

        st.insert(root->val);
        init_set(root->left, st);
        init_set(root->right, st);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        set<int> st;
        init_set(root, st);
        int min_diff  = INT_MAX;

        set<int>::iterator it = st.begin();
        while(it != st.end()){
            int x = *it;
            ++it;
            if(it == st.end()) break;
            int y = *it;
            min_diff = min(min_diff, y-x);
        }
        return min_diff;
    }
};