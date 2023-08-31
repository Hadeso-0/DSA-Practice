class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans = 1e9;
        vector<int> dp(n+1, ans);

        dp[0] = 0;
        for(int i=0; i<=n; ++i){
            int st = max(0, i-ranges[i]);
            int et = min(n, i+ranges[i]);
            for(int j = st; j<=et; ++j){
                dp[et] = min(dp[et], dp[j]+1); 
            }
        }

        if(dp[n] == ans) return -1;
        return dp[n];
    }
};