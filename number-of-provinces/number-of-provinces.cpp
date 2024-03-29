class Solution {
    void bfs(int i, vector<vector<int>>& g, vector<bool>& vis, queue<int>& q){
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int fr = q.front(); q.pop();
            cout<<fr<<" ";
            for(int j=0; j < g[fr].size(); ++j){
                if(fr!=j && !vis[j] && g[fr][j] == 1){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        vector<bool> vis(n, false);

        // vector<vector<int>> g(n);
        // for(int i=0; i<n; ++i){
        //     for(int j=0; j<n; ++j){
        //         if(i == j) continue;
        //         if(isConnected[i][j]){ 
        //             g[i].push_back(j);
        //             g[j].push_back(i);
        //         }
        //     }
        // }
        int ans = 0;
        queue<int> q;
        for(int i=0; i<n; ++i){
            if(!vis[i]){
                ++ans;
                bfs(i, g, vis, q);
                cout<<endl;
            }
        }
        return ans;
    }
};