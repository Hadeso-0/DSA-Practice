class Solution {
    int mod= 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int> dp(high+1, 0);
        dp[0] = 1;
        for(int i= 0; i<=high; i++){
            if(i >= zero) dp[i] = (dp[i] + dp[i-zero])%mod;
            if(i >= one)  dp[i] = (dp[i] + dp[i-one])%mod;
        }
        for(int i = low+1; i<=high; i++) 
            dp[i] = (dp[i] + dp[i-1])%mod;
        
        return dp[high];
    }
};