class Solution {
    int hades(int amt, vector<int>& coins, int idx, vector<vector<int>>& dp){
        if(dp[amt][idx] != -1) return dp[amt][idx];

        if(amt == 0) return 1;
        if(idx == coins.size()){
            return 0;
        }

        int ans = 0;
        if(coins[idx] <= amt){
            ans += hades(amt-coins[idx], coins, idx, dp);
        }
        ans += hades(amt, coins, idx+1, dp);
        
        return dp[amt][idx] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        // vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, -1));
        // return hades(amount, coins, 0, dp);

        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1, 0));
        for(int i=0; i<=n; ++i){
            dp[0][i] = 1;
        }

        for(int amt = 1; amt <= amount; ++amt){
            for(int idx = 1; idx<=n; ++idx){
                dp[amt][idx] = dp[amt][idx-1];
                if(coins[idx-1] <= amt){
                    dp[amt][idx] += dp[amt-coins[idx-1]][idx];
                }
            }
        }

        return dp[amount][n];
    }
};