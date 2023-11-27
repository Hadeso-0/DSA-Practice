class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> gr = {
        {4,6},
        {6,8},{7,9},{4,8},
        {3,9,0},{},{1,7,0},
        {2,6},{1,3},{2,4}
    };

    int knightDialer(int n) {
        long long ans = 0;
        
        vector<vector<int>> dp(n+1, vector<int>(10,0));
        for(int i=0; i<10; ++i){
            dp[1][i] = 1;
        }

        for(int i=2; i<=n; ++i){
            for(int j=0; j<10; ++j){
                for(auto prev: gr[j]){
                    dp[i][j] = (dp[i][j] + dp[i-1][prev])%mod;
                }
            }
        }

        for(int i=0; i<10; ++i){
            ans = (ans+ dp[n][i])%mod;
        }
        return ans%mod;     
    }

};