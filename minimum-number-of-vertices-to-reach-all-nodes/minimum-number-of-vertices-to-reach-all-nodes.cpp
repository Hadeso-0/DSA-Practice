class Solution {
    void topo_sort(vector<vector<int>> &gr, stack<int> &topo, vector<bool> &vis, int s)
    {
        if(vis[s]) return;
        
        vis[s] = true;
        
        for(int e : gr[s]) topo_sort(gr, topo, vis, e);
        topo.push(s);
    }

    void dfs(vector<vector<int>> &gr, vector<bool> &vis, int s, int &i)
    {
        if(vis[s]) return;
        vis[s]=true;
        i++;
        for(int e:gr[s]) dfs(gr, vis, e, i);
    }
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        
        for(auto &v: edges) gr[v[0]].push_back(v[1]);

        stack<int> topo;
        vector<bool> vis(n, false);
        vector<int> ans;

        for(int i=0;i<n;i++) topo_sort(gr, topo, vis, i);
        for(int i=0;i<n;i++) vis[i]=false;

        int i=0;
        while(topo.size() and i<n)
        {
            int x = topo.top();
            topo.pop();
            if(!vis[x])
            {
                ans.push_back(x);
                dfs(gr, vis, x, i);
            }
        }
        return ans;
    }
};