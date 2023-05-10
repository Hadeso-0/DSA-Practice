class Solution {
    void solve(int x, int n, int k, vector<int>& tmp, vector<vector<int>>& ans){
        if(n == 0 && k==0){
            ans.push_back(tmp);
            return;
        }
        if(x == 10 || k == 0) return;

        if(x <= n) {
            tmp.push_back(x);
            solve(x+1, n-x, k-1, tmp, ans);
            tmp.pop_back();
        }
        solve(x+1, n, k, tmp, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(1,n,k,tmp,ans);
        return ans;
    }
};