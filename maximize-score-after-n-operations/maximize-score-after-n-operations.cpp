class Solution {
    int solve(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& gcd){
        int m = nums.size(), n = nums.size()/2;
        if(op > n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0;i<m;i++){
            if( (mask & (1<<i)) ) continue;
            for(int j=i+1;j<m;j++){
                if( (mask & (1<<j)) ) continue;
                
                int newMask = (1<<i) | (1<<j) | mask;
                int score = op * gcd[i][j] + solve(nums, op+1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        return dp[mask];
    }
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> gc(n+1, vector<int>(n+1,0));
        vector<int> dp(1<<14, -1);
        for(int i =0; i<n; i++){
            for(int j = i+1; j<n; j++){
                gc[i][j] = __gcd(nums[i],nums[j]);
            }
        }   

        return solve(nums, 1, 0, dp, gc);
    }
};