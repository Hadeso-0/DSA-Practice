class Solution {
    void solve(int i, vector<int>& nums, vector<int>& temp, set<vector<int>>& temp_ans){
        if(i == nums.size()){ 
            temp_ans.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums, temp, temp_ans);
        temp.pop_back();
        solve(i+1, nums, temp, temp_ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> temp_ans;
        solve(0, nums, temp, temp_ans);
        vector<vector<int>> ans;
        for(auto& x : temp_ans){
            ans.push_back(x);
        }
        return ans;
    }
};