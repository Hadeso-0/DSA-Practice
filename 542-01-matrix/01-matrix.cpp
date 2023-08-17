class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0) return mat;
        
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }    
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        while(!q.empty()){
            int x = (q.front()).first;
            int y = (q.front()).second;
            q.pop();

            for(int d=0; d<4; ++d){
                int x_n = x + dx[d];
                int y_n = y + dy[d];
                if(x_n >= 0 && y_n>=0 && x_n<n && y_n<m && (mat[x_n][y_n] == 1) && (ans[x_n][y_n] > 1+ans[x][y])){
                    ans[x_n][y_n] = 1 + ans[x][y];
                    q.push({x_n, y_n});
                }
            }
        }
        return ans;
    }
};