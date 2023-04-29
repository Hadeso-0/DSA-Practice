class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols,110));
        queue<pair<int,int>> q;
        
        int fresh_oranges = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh_oranges++;
                }
            }
        }

        int ans = 0;
        if(fresh_oranges == 0) return ans;


        while(!q.empty()){
            int sz= q.size();
            for(int i=0; i<sz; i++){
                pair<int,int> temp = q.front();
                int r = temp.first;
                int c = temp.second;
                q.pop();
                if(r > 0 && grid[r-1][c] == 1){
                    fresh_oranges--;
                    grid[r-1][c] = 2;
                    q.push({r-1,c});
                }
                if(r < rows-1 && grid[r+1][c] == 1){
                    fresh_oranges--;
                    grid[r+1][c] = 2;
                    q.push({r+1,c});
                }
                if(c > 0 && grid[r][c-1] == 1){
                    fresh_oranges--;
                    grid[r][c-1] = 2;
                    q.push({r,c-1});
                }
                if(c < cols-1 && grid[r][c+1] == 1){
                    fresh_oranges--;
                    grid[r][c+1] = 2;
                    q.push({r,c+1});
                }
            }
            ans++;
        }
        return fresh_oranges == 0 ? ans-1 : -1;
    }
};