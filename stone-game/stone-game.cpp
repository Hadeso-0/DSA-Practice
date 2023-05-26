class Solution {
    long long solve(int n, vector<long long>& arr){
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        for(int i=1; i<=n; ++i){
            dp[i][i] = arr[i] - arr[i-1];
        }

        for(int i=n; i>=1; --i){
            for(int j=i+1; j<=n; ++j){
                long long ans  = (arr[j]-arr[i-1]);
                long long temp = min(dp[i+1][j], dp[i][j-1]);
                dp[i][j] = ans - temp; 
            }
        }
 
        return dp[1][n];
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<long long> arr(n+1, 0);
        for(int i=1; i<=n; ++i){
            arr[i] = (arr[i-1] + (piles[i-1]*1LL));
        }

        return solve(n, arr) > arr[n]/2;
    }
};