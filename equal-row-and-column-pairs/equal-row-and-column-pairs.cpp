class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<string,int> mp;
        for(int i=0; i<n ; ++i){
            string s = "";
            for(int j=0; j<m; ++j){
                s += to_string(grid[i][j]);
                s.push_back('$');
            }
            // cout<<s<<endl;
            ++mp[s];
        } 
        // cout<<endl;
        int ans = 0;
        for(int j=0; j<m ; ++j){
            string s = "";
            for(int i=0; i<n; ++i){
                s += to_string(grid[i][j]);
                s.push_back('$');
            }
            // cout<<s<<endl;
            ans += mp[s];
        } 
        return ans;
    }
};