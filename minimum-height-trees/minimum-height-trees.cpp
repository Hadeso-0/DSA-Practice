class Solution {
    int bfs(int root, vector<vector<int>>& g, queue<int>& q){
        q.push(root);
        vector<int> dis(g.size(), -1);
        dis[root] = 0;

        while(!q.empty()){
            int fr = q.front(); q.pop();
            for(auto& ch : g[fr]){
                if(dis[ch] == -1){ 
                    dis[ch] = 1+dis[fr];
                    q.push(ch);
                }
            }        
        }
        int ans = root;
        int max_dist = INT_MIN;
        for(int i=0; i<g.size(); ++i) {
            if(dis[i] > max_dist){
                ans = i;
                max_dist = dis[i];
            }
        }
        return ans;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<int> q; map<int,vector<int>> mp;
        int end1 = bfs(0, g, q);
        int end2 = bfs(end1, g, q);

        vector<int> par(n, -1);
        vector<bool> vis(n, false);
        q.push(end1);
        vis[end1] = true;
        par[end1] = -1;
        while(!q.empty()){
            int fr = q.front(); q.pop();
            for(auto& ch : g[fr]){
                if(!vis[ch]){ 
                    par[ch] = fr;
                    vis[ch] = true;
                    q.push(ch);
                }
            }        
        }

        vector<int> path;
        while(end2 != -1){
            path.push_back(end2);
            end2 = par[end2];
        }

        if(path.size() % 2 == 0){
            return {path[path.size()/2], path[(path.size()/2)-1]};
        }
        return {path[path.size()/2]};
    }
};