class Comp{
    public:
    bool operator()(const vector<int>& a, vector<int>& b){
        return a[2] > b[2];
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

        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));
        int des = (n*m) - 1;
        int ans = INT_MAX;

        priority_queue<vector<int>, vector<vector<int>>, Comp> q; // i,j,cost
        q.push({0, 0, 0});
        dis[0][0] = 0;

        while(!q.empty()){
            int i = (q.top())[0];
            int j = (q.top())[1];
            int cst = (q.top())[2];
            q.pop();
            
            // cout<<"("<<i<<","<<j<<","<<cst<<") -> ";
            if((i == n-1) && (j == m-1)){
                return cst;
            }
            // for(auto& to : gr[src]){
            //     int cst_to = (cst + to.first);
            //     if(dis[to.second] > cst_to){
            //         q.push({cst_to, to.second});
            //         dis[to.second] = cst_to;
            //     }
            // }

            for(int d=1; d<=4; ++d){
                int i_n = i+dx[d]; int j_n = j+dy[d];
                
                if((i_n < n) && (i_n>=0) && (j_n < m) && (j_n>=0)){
                    int wt = (d == grid[i][j]) ? 0 : 1;
                    int will_take = cst + wt;
                    if(dis[i_n][j_n] > will_take){
                        q.push({i_n, j_n, will_take});
                        dis[i_n][j_n] = will_take;
                    }
                
                }
            }
        }

        return -1;
    }
};