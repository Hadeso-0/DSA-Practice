class Solution {
    bool isCycle(vector<vector<int>>& g, int node, vector<bool>& vis, vector<bool>& dfsRun){
        bool ans = false;
        vis[node] = true;
        dfsRun[node] = true;

        for(auto ch : g[node]){
            if(vis[ch]) {
                if(dfsRun[ch]) return true;
            }
            else{
                ans = ans || isCycle(g, ch, vis, dfsRun);
                if(ans) return ans;
            }
        }
        
        dfsRun[node] = false;
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses, false);
        vector<bool> dfsRun(numCourses, false);
        
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(isCycle(adj, i, vis, dfsRun)) return false;
            }
        }
        return true;
    }
};