class Solution {
    // int solve(int idx, bool signal, int fee, vector<int>& price, vector<vector<int>>& dp){
    //     if(idx == price.size()) return 0;
    //     if(dp[idx][signal] != -1) return dp[idx][signal];
 
    //     int gain = 0;
    //     if(signal){
    //         gain = solve(idx+1, 1-signal, fee, price, dp) - price[idx] - fee;
    //     }
    //     else{
    //         gain = solve(idx+1, 1-signal, fee, price, dp) + price[idx];
    //     }
        
    //     int skip = solve(idx+1, signal, fee, price, dp);
        
    //     return dp[idx][signal] = max(gain, skip);
    // }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0,1,fee,prices, dp);
        
        int gain, skip;        
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i = n-1; i>=0; i--){
            for(int signal = 0; signal <= 1; signal++){
                gain = 0;
                if(signal){
                    gain = dp[i+1][1-signal] - prices[i];
                }
                else{
                    gain = dp[i+1][1-signal]+ prices[i] - fee;
                }
                skip = dp[i+1][signal];
                dp[i][signal] = max(gain, skip);
            }
        }
        return dp[0][1];
    }
};