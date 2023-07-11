class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>> gr(n+1);
        for(auto& ed : times){
            gr[ed[0]].push_back({ed[1], ed[2]});
        }

        vector<int> dis(n+1, 1e8);
        dis[k] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int t = -1*pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            for(auto& con : gr[cur]){
                if(dis[con.first] > t+con.second){
                    dis[con.first] = t+con.second;
                    pq.push({-dis[con.first], con.first});
                }
            }
        }
        int ans = -1;
        for(int i=1; i<=n; ++i){
            if(dis[i] > ans) ans = dis[i];
        }
        if(ans == 1e8) return -1;
        return ans;
    }
};