class Solution {
    int solve(int idx, bool buy, vector<int>& price, vector<vector<int>>& dp){
        if(idx >= price.size()) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];

        int gain = 0;
        if(buy){
            // can buy or skip
            gain = solve(idx+1, 0, price, dp) - price[idx];
        }
        else{
            // can sell or skip
            gain = solve(idx+2, 1, price, dp) + price[idx];
        }
        int skip = solve(idx+1, buy, price, dp);
        
        return dp[idx][buy] = max(gain, skip);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0,1, prices, dp);
    }
};