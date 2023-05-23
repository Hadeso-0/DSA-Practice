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
    // int pathSumFrmHere(TreeNode* root, long long target){
    //     if(root == NULL) return 0;

    //     int ans = 0;
    //     if((root->val)*1ll == target) ++ans;
    //     long long newTarget = target - (root->val)*1ll;
    //     ans += pathSumFrmHere(root->left, newTarget);
    //     ans += pathSumFrmHere(root->right, newTarget);

    //     return ans;
    // }
    int solve(TreeNode* root, long long curSum,  int target, map<long long , int>& mp){
        if(root == NULL){
            return 0;
        } 
        curSum += (root->val)*1ll;
        int ans = mp[curSum - (target*1ll)];
        ++mp[curSum];

        ans += solve(root->left, curSum, target, mp);
        ans += solve(root->right, curSum, target, mp);

        --mp[curSum];
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        map<long long , int> mp;
        ++mp[0];
        int ans = solve(root, 0LL, targetSum, mp);
        return ans;
    }
};