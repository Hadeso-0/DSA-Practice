class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& rels, int k) {
        vector<int> gr(n, 0);
        for(auto& rel : rels){
            int pre = rel[0]-1;
            int crs = rel[1]-1;

            gr[crs] |= (1<<pre);
        }
        vector<int> prereqs(1<<n, 0);
        for(int i=0; i<(1<<n); ++i){
            for(int j=0; j<n; ++j){
                if(i& (1<<j)){
                    prereqs[i] |= gr[j];
                }
            }
        }

        // dp[i]: minimum number of semesters of mask i, 
        // the set bits are courses that have not been taken
        vector<int> dp(1 << n, n + 1);
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            // iterate all submask of mask i, and this mask is the mask of last semester
            for (int j = i; j; j = (j - 1) & i) {
                if (__builtin_popcount(j) > k) {
                    continue;
                }

                int already_taken = i ^ ((1 << n) - 1);
                if ((already_taken & prereqs[j]) == prereqs[j]) {
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};