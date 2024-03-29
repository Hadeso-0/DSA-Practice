class Solution {
    // int solve(int idx, bool buy, int limit, vector<int>& price, vector<vector<vector<int>>>& dp){
    //     if(idx == price.size() || limit == 0) 
    //         return 0;

    //     if(dp[idx][buy][limit] != -1){
    //         return dp[idx][buy][limit];
    //     }
    //     if(buy){
    //         // I can either buy the stock or skip
    //         int bought = dp[idx+1][0][limit];
    //         if(bought == -1) bought = solve(idx+1, 0, limit, price, dp);
    //         bought -= price[idx];
            
    //         int skipped = dp[idx+1][1][limit];
    //         if(skipped == -1) skipped = solve(idx+1, 1, limit, price, dp);

    //         return dp[idx][buy][limit] = max(bought, skipped);
    //     }
    //     else{
    //         // I can either sell the stock or skip
    //         int sold = dp[idx+1][1][limit-1];
    //         if(sold == -1) sold = solve(idx+1, 1, limit-1, price, dp);
    //         sold += price[idx];

    //         int skipped = dp[idx+1][0][limit];
    //         if(skipped == -1) skipped = solve(idx+1, 0, limit, price, dp);

    //         return dp[idx][buy][limit] = max(sold, skipped);
    //     }
    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (k+1, -1)));
        // return solve(0,1,k,prices,dp);

        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int> (k+1, 0)));
        for(int idx=n-1; idx>=0; idx--){
            for(int buy = 0; buy<=1; buy++){
                for(int limit = 1; limit <= k; limit++){
                    if(buy){
                        // I can either buy the stock or skip
                        int bought = dp[(idx+1)%2][0][limit] - prices[idx];
                        int skipped = dp[(idx+1)%2][1][limit];
                        dp[idx%2][buy][limit] = max(bought, skipped);
                    }
                    else{
                        // I can either sell the stock or skip
                        int sold = dp[(idx+1)%2][1][limit-1] + prices[idx];
                        int skipped = dp[(idx+1)%2][0][limit];
                        dp[idx%2][buy][limit] = max(sold, skipped);
                    }   
                }
            }
        }
        return dp[0][1][k];
    }
};