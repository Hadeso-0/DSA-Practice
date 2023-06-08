class Solution {
    void serialize(TreeNode* node, string& treeStr) {
        if (node == nullptr){
            treeStr += "#";
            return;
        }

        treeStr += "$";
        treeStr += to_string(node->val);
        serialize(node->left, treeStr);
        serialize(node->right, treeStr);
    }
    bool kmp(string needle, string haystack) {
        int m = needle.length();
        int n = haystack.length();
        
        if (n < m)
            return false;
        
        vector<int> lps(m);
        int prev = 0;
        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[prev]) {
                prev += 1;
                lps[i] = prev;
                i += 1;
            } else {
                if (prev == 0) {
                    lps[i] = 0;
                    i += 1;
                } else {
                    prev = lps[prev-1];
                }
            }
        }
        
        int haystackPointer = 0;
        int needlePointer = 0;
        
        while (haystackPointer < n) {
            if (haystack[haystackPointer] == needle[needlePointer]) {
                needlePointer += 1;
                haystackPointer += 1;
                if (needlePointer == m)
                    return true;                
            } else {                
                if (needlePointer == 0) {
                    haystackPointer += 1;                    
                } else {
                    needlePointer = lps[needlePointer-1];
                }
            }
        }
        
        return false;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string r = "";
        serialize(root, r);
        string s = "";
        serialize(subRoot, s);                
        return kmp(s, r);
    }
};