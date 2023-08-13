class Solution {
    bool solve(vector<int>& nums, int idx, int end, vector<int>& dp){
        if(idx >= end) return true;
        if(idx == end-1) return false;
        if(dp[idx] != -1) return dp[idx];

        bool ans = false;
        if(nums[idx] == nums[idx+1]){
            if(solve(nums, idx+2, end, dp))
                return dp[idx] = true;
        }

        if(idx+3 <= end){
            if((nums[idx] == nums[idx+1]) and (nums[idx+1] == nums[idx+2])){
                if(solve(nums, idx+3, end, dp)) return dp[idx] = true;
            }
            if((nums[idx] == nums[idx+1]-1) and (nums[idx+1] == nums[idx+2]-1)){
                if(solve(nums, idx+3, end, dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, nums.size(), dp);        
    }
};