class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0,1,fee,prices, dp);
        
        int gain, skip;        
        vector<vector<int>> dp(2, vector<int>(2, 0));
        for(int i = n-1; i>=0; i--){
            for(int signal = 0; signal <= 1; signal++){
                gain = 0;
                if(signal){
                    gain = dp[(i+1)%2][1-signal] - prices[i];
                }
                else{
                    gain = dp[(i+1)%2][1-signal]+ prices[i] - fee;
                }
                skip = dp[(i+1)%2][signal];
                dp[i%2][signal] = max(gain, skip);
            }
        }
        return dp[0][1];
    }
};