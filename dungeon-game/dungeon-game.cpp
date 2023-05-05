class Solution {
    int ans = INT_MAX;
    int solve(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp){        
        if(dp[i][j] != 1) return dp[i][j];
        
        if(i==(dungeon.size()-1) && j == (dungeon[0].size()-1)){
            return min(dungeon[i][j], 0);
        }

        int dwn = INT_MIN;
        int rgt = INT_MIN;
        
        if(i < (dungeon.size()-1)){
            // move down
            dwn = dp[i+1][j];
            if(dwn == 1) dwn = solve(dungeon, i+1, j, dp); 
            
            dwn += dungeon[i][j];
        }
        if(j < (dungeon[0].size()-1)){
            // move right
            rgt = dp[i][j+1];
            if(rgt == 1) rgt = solve(dungeon, i, j+1, dp); 
            
            rgt += dungeon[i][j];
        }

        return dp[i][j] = min(0, max(dwn, rgt));
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 1));
        return 1-solve(dungeon,0,0,dp);
    }
};