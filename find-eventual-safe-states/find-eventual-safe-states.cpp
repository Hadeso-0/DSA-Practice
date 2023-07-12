class Solution {
    bool dfs(int node, vector<vector<int>>& gr, vector<bool>& isSafe, vector<bool>& runningDfs, vector<bool>& vis){
        runningDfs[node] = true;
        vis[node] = true;
        for(auto& next : gr[node]){
            if(!vis[next]){
                if(!dfs(next, gr, isSafe, runningDfs, vis)){
                    isSafe[node] = false;
                    return false;
                }
            }
            if(runningDfs[next]){
                isSafe[node] = false;
                return false;
            }
        }
        isSafe[node] = true;
        runningDfs[node] = false;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<bool> vis(n, false);
        vector<bool> isSafe(n, false);
        vector<bool> runningDfs(n, false);
        for(int i=0; i <n; ++i){
            if(!vis[i]){
                dfs(i, graph, isSafe, runningDfs, vis);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; ++i){
            if(isSafe[i]){
                ans.push_back(i);
            }
        }
        return ans;

    }
};