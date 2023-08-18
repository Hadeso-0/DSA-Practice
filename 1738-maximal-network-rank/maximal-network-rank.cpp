class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        vector<int> deg(n, 0);

        for(auto& road : roads){
            adj[road[0]][road[1]] = true;
            adj[road[1]][road[0]] = true;
            ++deg[road[0]];
            ++deg[road[1]];
        }

        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                ans = max(ans, deg[i]+deg[j]-adj[i][j]);
            }
        }

        return ans;
    }
};