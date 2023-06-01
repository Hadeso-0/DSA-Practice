class Solution {
    vector<int> dx = {1,1,0,-1,-1,-1,0,1};
    vector<int> dy = {0,1,1,1,0,-1,-1,-1};
    bool isValid(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<grid.size() && j<grid.size() && grid[i][j]!=1)
            return true;
        return false;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1) return -1;
        if(n == 1) return 1;
        
        // vector<vector<bool>> vis(n, vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        // vis[0][0] = 1;
        int ans = 0;

        while(!q.empty()){
            ++ans;
            for(int i = q.size()-1; i>=0; --i){
                pair<int,int> cell = q.front();
                q.pop();
                
                int x = cell.first;
                int y = cell.second;
                // cout<<x<<" "<<y<<endl;
                for(int i=0; i<8; i++){
                    // if(isValid(x+dx[i], y+dy[i], grid) && !vis[x+dx[i]][y+dy[i]]){
                    if(isValid(x+dx[i], y+dy[i], grid)){
                        q.push({x+dx[i], y+dy[i]});
                        grid[x+dx[i]][y+dy[i]] = 1;
                        // vis[x+dx[i]][y+dy[i]] = true;
                        if((x+dx[i] == n-1) && (y+dy[i] == n-1)) return ans+1;
                    }
                }
            }
        }

        return -1;
    }
};