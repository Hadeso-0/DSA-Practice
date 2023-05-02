class Solution {
    // int ans = 0;
    int dfs(int i,int j, vector<vector<int>>& mat, vector<vector<bool>>& vis, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>= mat.size() || j>= mat[0].size()) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int longestPath = 1;
        vis[i][j] = true;
        int x = 0;
        // top 
        if(i>0 && mat[i-1][j] > mat[i][j] && vis[i-1][j]==false){
            x = dp[i-1][j];
            if(x==-1) x = dfs(i-1,j,mat,vis,dp);
            longestPath = max(longestPath , 1 + x);
        }

        // left
        if(j>0 && mat[i][j-1] > mat[i][j] && vis[i][j-1]==false){
            x = dp[i][j-1];
            if(x==-1) x = dfs(i,j-1,mat,vis,dp);
            longestPath = max(longestPath , 1 + x);
        }

        // down
        if((i+1)<mat.size() && mat[i+1][j] > mat[i][j] && vis[i+1][j]==false){
            x = dp[i+1][j];
            if(x==-1) x = dfs(i+1,j,mat,vis,dp);
            longestPath = max(longestPath , 1 + x);
        }

        // right 
        if((j+1)<mat[0].size() && mat[i][j+1] > mat[i][j] && vis[i][j+1]==false){
            x = dp[i][j+1];
            if(x==-1) x = dfs(i,j+1,mat,vis,dp);
            longestPath = max(longestPath , 1 + x);
        }
        vis[i][j] = false;
        return dp[i][j] = longestPath;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int ans = 1;
        for(int i=0;i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                ans = max(ans, dfs(i,j,matrix,vis,dp));
            }
        }
        
        return ans;
    }
};