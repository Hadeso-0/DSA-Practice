class Solution {
    bool isEdge(string& a, string& b){
        int d =0 ;
        for(int i =0; i<a.size(); i++){
            if(a[i] != b[i]){
                d++;
            }
        }
        return (d==0 || d==2);
    }
    void bfs(int i, vector<bool>& vis, vector<vector<int>>& g, queue<int>& q){
        vis[i] = true;
        q.push(i);
        while(!q.empty()){
            int frnt = q.front();
            q.pop();
            for(auto ed : g[frnt]){
                if(!vis[ed]){
                    vis[ed] = true;
                    q.push(ed);
                }
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> g(n);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isEdge(strs[i],strs[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n, false);
        queue<int> q;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                bfs(i, vis, g, q);
            }
        }
        return ans;
    }
};