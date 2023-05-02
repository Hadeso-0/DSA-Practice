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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p != NULL){
                q.push(p->left);
                q.push(p->right);
                ans += to_string(p->val);
            }
            else{
                ans += "N";
            }
            ans += ",";
        }   
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'N') return NULL;
        int idx = 0;
        queue<string> temp;
        while(idx < data.size()){
            string t = "";
            while(data[idx] != ','){
                t += data[idx++];
            }
            temp.push(t);
            idx++;
        }
        
        idx = 1;
        TreeNode* root = new TreeNode(stoi(temp.front()));
        temp.pop();
        queue<TreeNode*> q;
        q.push(root);
        while(!temp.empty()){
            TreeNode* tp = q.front();
            q.pop();

            // Left SubTree
            if(temp.front()!="N"){
                tp->left = new TreeNode(stoi(temp.front()));
                q.push(tp->left);
            }
            temp.pop();

            // Right SubTree
            if(temp.front()!="N"){
                tp->right = new TreeNode(stoi(temp.front()));
                q.push(tp->right);
            }
            temp.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));