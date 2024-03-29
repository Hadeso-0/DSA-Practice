class Solution {
    // int solve(int n, vector<int>& dp){
    //     if(n==1) return 1;
    //     if(dp[n] != -1) return dp[n];
        
    //     int ans = n;
    //     for(int i=n/2; i>=2; i--){
    //         if(n%i == 0){
    //             int ops = (n/i)-1 + 1;
    //             ans = min(ans, ops + solve(i,dp));
    //         }
    //     }
    //     return dp[n] = ans;
    // }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<int> dp(n+1,1);
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            int ans = i;
            for(int j=i/2; j>=2; j--){
                if(i%j == 0){
                    int ops = (i/j)-1 + 1;
                    ans = min(ans, ops + dp[j]);
                }
            }
            dp[i] = ans;
        }
        
        return dp[n];
    }
};