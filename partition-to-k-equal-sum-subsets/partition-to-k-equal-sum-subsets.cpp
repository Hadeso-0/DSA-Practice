class Solution {
    int n;
    int vis[20];
    
    bool solve(vector<int>& nums, int numsIndex, int currSum, int& subsetSum, int k) {
        if(k == 1) return true;
        
        if(currSum == subsetSum) {
            return solve(nums, n-1, 0, subsetSum, k-1);
        }
        
        for(int i = numsIndex; i>=0; i--) {
            if(vis[i] || (currSum + nums[i] > subsetSum)) continue;
            
            vis[i] = 1;
            currSum += nums[i];
            
            if(solve(nums, i+1, currSum, subsetSum, k)) return true;
            
            vis[i] = 0;
            currSum -= nums[i];
        }
        return false;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); ++i) sum+=nums[i];

        if((sum%k != 0) || (sum == 0)) return false;
        int target = sum/k;

        n = nums.size();
        memset(vis, 0, sizeof(vis));
        sort(nums.begin(), nums.end(), greater<int>());
        
        vis[n-1] = 1;
        return solve(nums, n-1, nums[n-1], target, k);
    }
};