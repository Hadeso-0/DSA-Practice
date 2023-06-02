class Solution {
    int dfs(int i, vector<vector<int>>& g, vector<int>& vis){
        vis[i] = true;
        // if(dp[i] != -1) return dp[i];
        int ans = 0;
        // cout<<i<<"->";
        for(auto& x : g[i]){
            if(!vis[x]) ans += dfs(x, g, vis);
        }
        // return dp[i] = ans+1;
        return ans+1;
    }
    bool isConn(vector<int>& a, vector<int>& b){
        long long sep = ((a[1]*1LL-b[1]*1LL)*(a[1]*1LL-b[1]*1LL)) + ((a[0]*1LL-b[0]*1LL)*(a[0]*1LL-b[0]*1LL));
        if(sep*1LL <= a[2]*1LL*a[2]) return true;
        return false;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
    
        vector<vector<int>> g(n);
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(isConn(bombs[i], bombs[j]))
                    g[i].push_back(j);
                if(isConn(bombs[j], bombs[i]))
                    g[j].push_back(i);
            }
        }

        // for(int i=0; i<n; ++i){
        //     cout<<i<<"->";
        //     for(auto& j : g[i]) cout<<j<<" ";
        //     cout<<endl;
        // }

        vector<int> dp(n, -1);
        int ans = 0;
        for(int i=0; i<n; ++i){
            // if(!vis[i]){ 
                vector<int> vis(n, false);
                ans = max(ans, dfs(i, g, vis));
                // cout<<endl;
            // }
        }
        return ans;
    }
};