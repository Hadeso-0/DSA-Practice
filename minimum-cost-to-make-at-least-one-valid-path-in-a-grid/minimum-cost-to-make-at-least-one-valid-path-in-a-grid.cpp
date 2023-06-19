class Comp{
    public:
    bool operator()(const pair<int,int>& a, pair<int,int>& b){
        return a.first > b.first;
    }
};
class Solution {
    const vector<int> dx = {0,0,0,1,-1};
    const vector<int> dy = {0,1,-1,0,0};
    int getIdx(int i, int j, int n){
        return i*n + j;
    }
public:
    int minCost(vector<vector<int>>& grid) {    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<pair<int,int>>> gr(n*m);
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                // cout<<i*m+j<<" ";
                for(int d=1; d<=4; ++d){
                    int i_n = i+dx[d]; int j_n = j+dy[d];
                    if((i_n < n) && (i_n>=0) && (j_n < m) && (j_n>=0)){
                        int wt = (d == grid[i][j]) ? 0 : 1;
                        gr[i*m + j].push_back({wt, i_n*m + j_n});
                    }

                }
            }
            // cout<<endl;
        }

        // for(int i=0; i<n*m; ++i){
        //     cout<<i<<" --> ";
        //     for(auto& p : gr[i]){
        //         cout<<"("<<p.first<<","<<p.second<<"), ";
        //     }
        //     cout<<endl;
        // }

        vector<int> dis(n*m, INT_MAX);
        int des = (n*m) - 1;
        int ans = INT_MAX;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp> q; // cost, src
        q.push({0, 0});
        dis[0] = 0;

        while(!q.empty()){
            int cst = (q.top()).first;
            int src = (q.top()).second;
            q.pop();
            
            // cout<<"("<<src<<","<<cst<<") -> ";
            if(src == des){
                return cst;
            }
            for(auto& to : gr[src]){
                int cst_to = (cst + to.first);
                if(dis[to.second] > cst_to){
                    q.push({cst_to, to.second});
                    dis[to.second] = cst_to;
                }
            }
        }

        return 0;
    }
};