class Solution {
    vector<int> dy = {0,1,0,-1};
    vector<int> dx = {-1,0,1,0};
    void dfs(int x,int y, vector<vector<int>> &ht,vector<vector<int>> &vis){
        vis[x][y]=1;
        
        for(int i=0;i<4;i+=1){
            int x1= dx[i]+x,y1=dy[i]+y;

            if(x1>=0 && y1>=0 && x1<ht.size() && y1<ht[0].size() && !vis[x1][y1] && ht[x1][y1] >= ht[x][y]){
                dfs(x1,y1,ht,vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        vector<vector<int>> atlantic(n,vector<int>(m,0)),pacific(n,vector<int>(m,0));
        for(int i=0;i<m;++i){ // connect first row to pacific and last row to atlantic
            dfs(0,i,heights,pacific);
            dfs(n-1,i,heights,atlantic);
        }

        for(int i=0;i<n;++i){
            dfs(i,0,heights,pacific);
            dfs(i,m-1,heights,atlantic);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(atlantic[i][j] == pacific[i][j] && pacific[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};