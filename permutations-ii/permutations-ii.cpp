class Solution {
    set<vector<int>> temp;
    void solve(vector<int>& nums, int i){
        if(i == nums.size()){
            temp.insert(nums);
        }

        for(int j = i; j<nums.size(); ++j){
            if(i != j) swap(nums[i],nums[j]);
            solve(nums, i+1);
            if(i != j) swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        vector<vector<int>> ans;
        for(auto& it : temp){
            ans.push_back(it);
        }
        return ans;
    }
};