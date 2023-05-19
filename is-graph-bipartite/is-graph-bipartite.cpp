class Solution {
    bool bfs(vector<vector<int>>& graph, int i, vector<int>& col){
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(auto ngh : graph[k]){
                if(col[ngh] != -1){
                    if(col[ngh] == col[k]) return false;
                }
                else{
                    col[ngh] = 1-col[k];
                    q.push(ngh);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        
        for(int i=0; i<n; i++){
            if(col[i] == -1 && !bfs(graph, i, col)){
                col[i] = 0;
                return false;
            }
        }
        return true;
    }
};