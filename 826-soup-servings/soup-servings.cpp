class Solution {
    unordered_map<int, unordered_map<int, double>> dp;
    double solve(int i, int j){
        return (dp[max(0, i-4)][j] + dp[max(0, i-3)][max(0, j-1)] + dp[max(0, i-2)][max(0, j-2)] + dp[max(0, i-1)][max(0, j-3)])/4;
    }
public:
    double soupServings(int n) {
        int n_new = ceil(n/25.0);
        if(dp[n_new].find(n_new) != dp[n_new].end()){
            return dp[n_new][n_new];
        }
        
        dp[0][0] = 0.5;
        
        for(int i=1; i<=n_new; ++i){
            dp[i][0] = 0.0;
            dp[0][i] = 1.0;
            for(int j=1; j<=i; ++j){
                dp[i][j] = solve(i, j);
                dp[j][i] = solve(j, i);
            }

            if(dp[i][i] > 1-1e-5){
                return 1;
            }
        }

        return dp[n_new][n_new];
    }
};