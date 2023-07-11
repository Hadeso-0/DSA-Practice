class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> gr(n);
        for(auto& ed : edges){
            gr[ed[0]].push_back(ed[1]);
            gr[ed[1]].push_back(ed[0]);
        }

        vector<int> dis(n, 1e8);
        queue<int> q;
        vector<bool> vis(n, false);
        dis[0] = 0;
        q.push(0); vis[0] = true; int x = 0;

        while(!q.empty()){
            for(int i = q.size()-1; i>=0; --i){
                int fr = q.front(); q.pop();
                dis[fr] = min(dis[fr], x);
                
                for(auto& ch : gr[fr]){
                    if(!vis[ch]){
                        q.push(ch);
                        vis[ch] = true;
                    }
                }
            }
            ++x;
        }
        // for(auto& d : dis){
        //     cout<<d<<" ";
        // }
        int ans = 0;
        for(int i=1; i<n; ++i){
            if(patience[i] == 0){
                int num_reqs = (2*dis[i]);
                int last_rec = num_reqs + (2*dis[i]);
                ans = max(ans,last_rec);
                continue;
            }
            // Number of requests -> receive time of first req / patience;
            int num_reqs = (2*dis[i] / patience[i]);
            if(((2*dis[i]) % patience[i]) == 0) --num_reqs;

            int time_last_req = (num_reqs*patience[i]);
            int last_rec = time_last_req + (2*dis[i]);

            ans = max(ans, last_rec);
        }

        return ans+1;
    }   
};