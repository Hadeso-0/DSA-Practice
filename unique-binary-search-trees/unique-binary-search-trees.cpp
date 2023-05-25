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
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, dp);
    }
};