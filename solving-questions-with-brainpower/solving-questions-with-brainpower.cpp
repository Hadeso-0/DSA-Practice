class Solution {
    // long long solve(int idx, vector<vector<int>>& qs, vector<int>& dp){
    //     if(idx >= qs.size()) return 0;
    //     if(dp[idx] != -1) return dp[idx];
    //     long long incl, excl;

    //     // include idx
    //     incl = qs[idx][0] + solve(idx+1+(qs[idx][1]), qs, dp);
    //     // exclude idx
    //     excl = solve(idx+1, qs, dp);

    //     return dp[idx] = max(incl, excl);
    // }
public:
    long long mostPoints(vector<vector<int>>& qs) {
        int n = qs.size();
        vector<long long> dp(n+1, 0LL);
        // return solve(0, questions, dp);
        long long incl = 0;
        long long excl = 0;
        int idx_next = 0;

        for(int i=n-1; i>=0; i--){
            incl = 0;
            excl = 0;

            // include idx
            idx_next = min(i+1+qs[i][1], n);
            incl = qs[i][0]*1LL + dp[idx_next];
            // exclude idx
            excl = dp[i+1];

            dp[i] = max(incl, excl);
        }
        return dp[0];
    }
};