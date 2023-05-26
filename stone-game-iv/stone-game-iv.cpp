class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);

        dp[1] = true;
        for(int i=2; i<=n; ++i){
            bool temp = true;
            for(int j=1; (j*j) <= i; ++j){
                temp &= dp[i-(j*j)];
                if(!temp) break;
            }
            dp[i] = (1-temp);
        }
        // for(int i=0; i<=n; ++i) cout<<dp[i]<<" ";
        return dp[n];

        // for(int i=0; i<=n; ++i){
        //     if(dp[i]) continue;
        //     for(int k=1; i+(k*k)<=n; ++k)
        //         dp[i+(k*k)] = true;
        // }
        // return dp[n];
    }
};