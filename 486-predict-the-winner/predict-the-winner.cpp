class Solution {
    int solve(vector<int>& prefix, int i, int j, vector<vector<int>>& dp){
        if(i == j) return prefix[j]-prefix[i-1];
        if(dp[i][j] != -1) return dp[i][j];
        
        int tot = prefix[j] - prefix[i-1];
        int take_lft = tot - solve(prefix, i+1, j, dp);
        int take_rgt = tot - solve(prefix, i, j-1, dp);

        return max(take_lft, take_rgt);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0; i<n; ++i){
            prefix[i+1] = prefix[i] + nums[i];
        }
        long sum = prefix[n];

        for(int i=n; i>=1; --i){
            dp[i][i] = prefix[i]-prefix[i-1]; 
            for(int j=i+1; j<=n; ++j){

                int tot = prefix[j] - prefix[i-1];
                dp[i][j] = tot - min(dp[i+1][j], dp[i][j-1]);

            }
        }

        int p1 = dp[1][n];
        return 2*p1 >= sum;
    }
};