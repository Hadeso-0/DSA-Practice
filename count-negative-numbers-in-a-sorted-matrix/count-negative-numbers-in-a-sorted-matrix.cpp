class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int i = rows-1;
        int j = 0;
        int ans = 0;
        while(i>=0 && j<cols){
            if(grid[i][j] >= 0){
                ++j;
            }
            else{
                ans += (cols-j);
                --i;
            }
        }
        return ans;
    }
};