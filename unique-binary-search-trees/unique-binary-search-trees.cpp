class Solution {
    int solve(int s, int e, vector<vector<int>>& dp){
        if(s >= e) return 1;

        if(dp[s][e] != -1) return dp[s][e];

        int ans = 0;
        for(int rt = s; rt <= e; ++rt){
            // take root value = rt
            // root->left values < rt  -> ways =  solve(s, rt-1); 
            // root->right values > rt -> ways =  solve(rt+1, e);

            int temp1 = solve(s, rt-1, dp);
            int temp2 = solve(rt+1, e, dp);
            ans = ans + (temp1*temp2);
            // cout<<rt<<"->"<<temp1<<" "<<temp2<<endl;  
        }
        return dp[s][e] = ans;
    }
public:
    int numTrees(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        // return solve(1, n, dp);
        for(int i=0; i<= n+1; ++i){
            for(int j=0; j<=i; ++j){
                dp[i][j] = 1;
            }
        }

        for(int i=n; i>=1; --i){
            for(int j=i+1; j<=n; ++j){
                for(int k=i; k<=j; ++k){
                    dp[i][j] = dp[i][j] + (dp[i][k-1]*dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};