class Solution {
    vector<int> di = {1,0,-1,0};
    vector<int> dj = {0,-1,0,1};
    int MOD = 1e9+7;
    int ans = 0;
    int funct(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m){
        
        if(dp[i][j] != -1) 
            return dp[i][j];

        dp[i][j] = 1;
        for(int d=0; d<4; ++d){
            int i_nex = i + di[d]; int j_nex = j + dj[d];
            if(i_nex>=0 && j_nex>=0 && i_nex<n && j_nex<m){
                if(grid[i_nex][j_nex] > grid[i][j]){
                    
                    // paths starting from (i_new, jnew)
                    int ways = funct(i_nex, j_nex, grid, dp, n, m);

                    // add (i, j) before each path
                    dp[i][j] = (dp[i][j] + ways)%MOD;
                }
            }
        }
        return dp[i][j];
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n ,vector<int>(m,-1));
        
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                ans = (ans + funct(i, j, grid, dp, n, m))%MOD;
            }
        }

        return ans;
    }
};