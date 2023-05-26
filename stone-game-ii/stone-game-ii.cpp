class Solution {
    int solve(vector<int>& piles, vector<int>& suffSum, int idx, int M, vector<vector<int>>& dp){
        if(idx >= piles.size()) return 0;

        if(dp[idx][M] != -1) return dp[idx][M];

        int ans = INT_MIN;
        for(int x=1; x<=(2*M); ++x){
            if(idx + x > piles.size()) break;
            int M_new = max(x, M);
            int temp = solve(piles, suffSum, idx+x, M_new, dp);
            ans = max(ans, suffSum[idx]-temp);
        }
        return dp[idx][M] = ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sufSum(n+1, 0);
        for(int i=n-1; i>=0; --i){
            sufSum[i] = sufSum[i+1] + piles[i];
        }
        vector<vector<int>> dp(n+1, vector<int>((2*n)+1, -1));
        return solve(piles, sufSum, 0, 1, dp);
    }   
};