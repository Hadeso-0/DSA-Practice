
class Solution {
private:
    int dfs(vector<vector<int>> &arr,int i,int j,map<int,vector<int>> row[],map<int,vector<int>> col[],vector<vector<int>> &dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1;
        //move in row
        auto c = row[i].lower_bound(arr[i][j]+1);
        if(c != row[i].end()){
            vector<int> x = (*c).second;
            for(auto j_nex : x)
                ans = max(ans,1+dfs(arr,i,j_nex,row,col,dp));
        }
        //move in col
        auto r = col[j].lower_bound(arr[i][j]+1);
        if(r != col[j].end()){
            vector<int> x = (*r).second;
            for(auto i_nex : x)
                ans=max(ans,1+dfs(arr,i_nex,j,row,col,dp));
        }
        return dp[i][j] = ans;
    }
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size(),i,j;
        map<int,vector<int>> row[n];
        map<int,vector<int>> col[m];
        
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                int ele = mat[i][j];
                row[i][ele].push_back(j);
                col[j][ele].push_back(i);
            }
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
       
        for(i=0;i<n;++i){
            for(j=0;j<m;++j){
                ans = max( ans, dfs(mat,i,j,row,col,dp));
            }
        }
        return ans;
        
    }
};