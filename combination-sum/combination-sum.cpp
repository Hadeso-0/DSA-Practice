class Solution {
    void solve(int i, vector<int>& candidates, vector<int>& temp, int target, vector<vector<int>>& ans){
        if(target < 0) return;
        if(i == candidates.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            solve(i, candidates, temp, target-candidates[i], ans);
            temp.pop_back();
        }
        solve(i+1, candidates, temp, target, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,candidates, temp, target, ans);
        return ans;
    }
};