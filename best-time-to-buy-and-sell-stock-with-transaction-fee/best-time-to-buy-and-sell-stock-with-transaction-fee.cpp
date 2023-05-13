class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0,1,fee,prices, dp);
        
        int gain, skip;        
        int buy = 0;
        int sell = 0;
        
        for(int i = n-1; i>=0; i--){
            int temp = sell;
            sell = max(buy + prices[i] - fee , sell);
            buy  = max(temp - prices[i] , buy);
        }
        return buy;
    }
};