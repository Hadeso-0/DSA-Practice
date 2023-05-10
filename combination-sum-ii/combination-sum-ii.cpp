class Solution {
    void solve(int i, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(target < 0) return;
        if(target == 0){ 
            ans.push_back(temp);
            return;
        }
        
        for(int next_i = i; next_i < nums.size(); ++next_i){
            if(next_i > i && nums[next_i-1] == nums[next_i]) continue;
            
            if(nums[next_i] <= target){
                temp.push_back(nums[next_i]);
                solve(next_i+1, nums, target-nums[next_i], ans, temp);
                temp.pop_back();
            }else{
                break;
            }
            // solve(next_i+1, nums, target, ans, temp);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> vecs;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0,candidates, target, ans, temp);
        // for(auto& v : vecs){
        //     ans.push_back(v);
        // }
        return ans;
    }
};