/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string& ans){
        if(root == NULL) return;

        ans += to_string(root->val) + "#";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        cout<<ans;
        return ans;
    }

    TreeNode* makeTree(vector<int>& nodes, int l, int r){
        if(l > r) return NULL;
        if(l == r){
            return new TreeNode(nodes[l]);
        }
        TreeNode* root = new TreeNode(nodes[l]);
        
        int i = l;
        for(i=l+1; i<=r; ++i){
            if(nodes[i] > nodes[l]) break;
        }

        root->left = makeTree(nodes, l+1, i-1);
        root->right = makeTree(nodes, i, r);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> nodes;
        int cur = 0;
        for(int i=0; i<data.size(); ++i){
            if(data[i] == '#'){
                nodes.push_back(cur);
                cur = 0;
            }
            else{
                cur = (cur*10 + (data[i]-'0'));
            }
        }
        int n = nodes.size();
        return makeTree(nodes, 0, n-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;