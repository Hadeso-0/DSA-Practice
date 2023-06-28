class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // // Bellman Ford
        // vector<double> dist(n);
        // dist[start] = 1.00000;

        // for(int i=0; i<n-1; ++i){
        //     bool isUpd = false;
        //     for(int j=0; j< edges.size(); ++j){
        //         int u = edges[j][0];
        //         int v = edges[j][1];
        //         double dis = succProb[j];
        //         if(dist[u]*dis > dist[v]){
        //             dist[v] = dist[u]*dis;
        //             isUpd = true;
        //         }
        //         if(dist[v]*dis > dist[u]){
        //             dist[u] = dist[v]*dis;
        //             isUpd = true;
        //         }
        //     }
        //     if(!isUpd) break;
        // }

        // return dist[end];


        // // Modified Bellman Ford
        // unordered_map<int, vector<pair<int, double>>> adj(n);
        // for(int i=0; i<edges.size(); ++i){
        //     adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        //     adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        // }

        // vector<double> dist(n);
        // dist[start] = 1.00;

        // queue<int> q;
        // q.push(start);
        // while(!q.empty()){
        //     int t = q.front(); q.pop();
        //     for(auto& ch : adj[t]){
        //         if(dist[t]*ch.second > dist[ch.first]){
        //             dist[ch.first] = dist[t]*ch.second;
        //             q.push(ch.first);
        //         }
        //     }
        // }
        // return dist[end];

        // Dijkstra's 
        unordered_map<int, vector<pair<int, double>>> adj(n);
        for(int i=0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> dist(n);
        dist[start] = 1.00;

        priority_queue<pair<double,int>> q;
        q.push({1.0, start});
        while(!q.empty()){
            int t = q.top().second;
            double s = q.top().first; q.pop();
            if(t == end) return s;

            for(auto& ch : adj[t]){
                if(s*ch.second > dist[ch.first]){
                    dist[ch.first] = s*ch.second;
                    q.push({dist[ch.first], ch.first});
                }
            }
        }
        return 0.00;
    }
};