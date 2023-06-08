class Solution {
    void dfs(int node, int par, vector<vector<int>>& g, vector<int>& low, vector<int>& disc, vector<bool>& vis, int t, vector<vector<int>>& ans){
        vis[node] = 1;
        disc[node] = t;
        low[node] = t;
        ++t;

        for(auto& ch : g[node]){
            if(ch == par) continue;
            if(vis[ch]){ // update minimum path 
                low[node] = min(low[node], disc[ch]);
            }
            else{
                dfs(ch, node, g, low, disc, vis, t, ans);
                low[node] = min(low[node], low[ch]);
                
                if(low[ch] > disc[node]){
                    ans.push_back({node, ch});
                }

            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        for(auto& e : connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> low(n,-1);
        vector<int> disc(n,-1);
        vector<bool> vis(n,false);
        vector<vector<int>> ans;

        for(int i=0; i<n; ++i){
            if(!vis[i]) dfs(i, -1, g, low, disc, vis, 0, ans);
        }
        return ans;
    }
};