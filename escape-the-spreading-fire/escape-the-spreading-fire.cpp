class Solution {
    const int inf = 0x3f3f3f3f;
    int n, m;
    int fire_time[300][300];
    int dis[300][300];
    
    int fx[4] = {-1,+0,+1,+0};
    int fy[4] = {+0,-1,+0,+1};
    
    int invalid(int x, int y, vector<vector<int>>& grid) {
        return x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 2;
    }
    
    void init_fire(vector<vector<int>>& grid) {
        queue <pair<int, int>> Q;
        memset(fire_time, inf, sizeof(fire_time));
       
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    Q.push({i, j});
                    fire_time[i][j] = 0;
                }
            }
        }
        
        while(!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            int x = cur.first;
            int y = cur.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + fx[i];
                int ny = y + fy[i];
                if (invalid(nx, ny, grid)) continue;
                if (fire_time[nx][ny] > fire_time[x][y] + 1) {
                    fire_time[nx][ny] = fire_time[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    
    int minimum_time(int wait, vector<vector<int>>& grid) {
        memset(dis, inf, sizeof(dis));
        queue<pair<int, int>> Q; 
        Q.push({0, 0});
        dis[0][0] = wait;
        
        while(!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();
            int x = cur.first, y = cur.second;
            for (int i = 0; i < 4; i++) {
                int nx = x + fx[i];
                int ny = y + fy[i];
                if(invalid(nx, ny, grid)) continue;
                
                int new_min = min(dis[nx][ny], dis[x][y] + 1);
                
                if (nx == n - 1 && ny == m - 1 && new_min <= fire_time[nx][ny]) 
                    return new_min;
                
                if (new_min >= fire_time[nx][ny]) 
                    continue;
                
                if (dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    Q.push({nx, ny});
                }
            }
        }
        
        return inf + 1;
    }
    
    int find_wait(vector<vector<int>>& grid) {
        if (fire_time[n - 1][m - 1] == inf) {
            return minimum_time(0, grid) < inf ? 1e9 : -1;
        }
        
        int max_pos = (n * m) + 1;
        int l = 0, r = max_pos, ans = -1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;

            if(minimum_time(mid, grid) <= fire_time[n - 1][m - 1]) {
                l = mid + 1;
                ans = mid;
            }else {
                r = mid - 1;
            }
        }
        
        return ans == max_pos ? 1e9 : ans;
    }

    public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        init_fire(grid);
        return find_wait(grid);
    }
};