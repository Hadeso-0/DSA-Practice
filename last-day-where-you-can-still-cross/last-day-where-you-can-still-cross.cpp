class Solution {
    const vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    bool isPossible(vector<vector<bool>>& grid, int n, int m){
        queue<pair<int,int>> q;
      
        for(int j=0; j<m; ++j){
            if(grid[0][j]){ q.push({0,j}); grid[0][j] = false; }
        }


        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto& d : dirs){
                int x_new = x + d[0];
                int y_new = y + d[1];

                if(x_new < 0 || x_new >= n || y_new <0 || y_new>=m) continue;
                if(grid[x_new][y_new]){
                    if(x_new == n-1) return true;
                    q.push({x_new, y_new});
                    grid[x_new][y_new] = false;
                }
            }
        }
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        // Binary Search on index;
        int l = 0; int r = cells.size()-1;
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            vector<vector<bool>> grid(row, vector<bool>(col, true));
            for(int i=0; i<=mid; ++i){
                grid[cells[i][0]-1][cells[i][1]-1] = false;
            }

            if(isPossible(grid, row, col)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans+1;

    }
};