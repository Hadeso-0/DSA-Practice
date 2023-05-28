class Solution {

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> cts;
        cts.push_back(0);
        for(auto& i : cuts) cts.push_back(i);
        cts.push_back(n);

        int m = cts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, 0));  
        // return solve(cts, 0, m-1, dp);

        for(int i=m-1; i>=0; --i){
            for(int j=i+2; j<m; ++j){
                int ans = 1e8;
                for(int cut=i+1; cut<j; ++cut){
                    ans = min(ans, dp[i][cut] + dp[cut][j]); 
                }

                dp[i][j] = ans + (cts[j] - cts[i]);
            }
        }
        // for(int i=0; i<m; ++i){
        //     for(int j=0; j<m; ++j){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][m-1];
    }
};