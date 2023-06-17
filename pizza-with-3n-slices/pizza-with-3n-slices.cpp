class Solution {
    int solve(int l, int r, vector<int>& slices, int slices_left, vector<vector<int>>& dp){
        if(slices_left == 0 || l> r) return 0;
        
        if(dp[l][slices_left] != -1) return dp[l][slices_left];

        int incl = slices[l] + solve(l+2, r, slices, slices_left-1, dp);   
        int excl = solve(l+1, r, slices, slices_left, dp);   

        return dp[l][slices_left] = max(incl, excl);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n+1, vector<int>(n/3+1, -1));
        vector<vector<int>> dp2(n+1, vector<int>(n/3+1, -1));
        return max(solve(0,n-2,slices, n/3, dp1), solve(1,n-1,slices, n/3, dp2));
    }
};