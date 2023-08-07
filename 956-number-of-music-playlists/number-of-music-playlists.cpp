class Solution {
    vector<int> fact;
    int mod = 1e9+7;
public:
    Solution() {
        fact.resize(101, 1);
        for(int i=1; i<=100; ++i){
            fact[i] = (i*1LL*fact[i-1]%mod)%mod;
        }
    }
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;
              
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return dp[goal][n];
    }
};