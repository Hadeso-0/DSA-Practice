class Solution {
    // int ans = INT_MAX;
    // int solve(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>>& dp){        
    //     if(dp[i][j] != 1) return dp[i][j];
        
    //     if(i==(dungeon.size()-1) && j == (dungeon[0].size()-1)){
    //         return min(dungeon[i][j], 0);
    //     }

    //     int dwn = INT_MIN;
    //     int rgt = INT_MIN;
        
    //     if(i < (dungeon.size()-1)){
    //         // move down
    //         dwn = dp[i+1][j];
    //         if(dwn == 1) dwn = solve(dungeon, i+1, j, dp); 
            
    //         dwn += dungeon[i][j];
    //     }
    //     if(j < (dungeon[0].size()-1)){
    //         // move right
    //         rgt = dp[i][j+1];
    //         if(rgt == 1) rgt = solve(dungeon, i, j+1, dp); 
            
    //         rgt += dungeon[i][j];
    //     }

    //     return dp[i][j] = min(0, max(dwn, rgt));
    // }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>> dp(rows+1, vector<int>(cols+1, INT_MAX));
        // return 1-solve(dungeon,0,0,dp);

        dp[rows-1][cols-1] = min(dungeon[rows-1][cols-1],0);
        for(int i = rows-2; i>=0; i--){
            dp[i][cols-1] = min(0, dungeon[i][cols-1]+dp[i+1][cols-1]);
        }
        for(int j = cols-2; j>=0; j--){
            dp[rows-1][j] = min(0, dungeon[rows-1][j]+dp[rows-1][j+1]);
        }

        for(int i=rows-2; i>=0; i--){
            for(int j=cols-2; j>=0; j--){
                int rgt = dp[i][j+1] + dungeon[i][j];
                int dwn = dp[i+1][j] + dungeon[i][j];
                dp[i][j] = min(0, max(rgt, dwn));
            }
        }

        return 1-dp[0][0];
    }
};