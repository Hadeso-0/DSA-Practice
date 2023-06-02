class Solution {
    vector<int> dx = {0,1,-1,0};
    vector<int> dy = {1,0,0,-1};

    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]) return 0;
        vis[i][j] = true;
        int ans = 1;

        for(int d=0; d<4; ++d){
            int i_new = i + dx[d];
            int j_new = j + dy[d];
            ans += dfs(i_new, j_new, grid, vis);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans, dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};