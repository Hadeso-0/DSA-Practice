class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int busyTime, vector<vector<int>>& v)
    {
        if(busyTime >= ((int)v.size() - idx)) return 0;
        if(idx == v.size()){
            // if(busyTime >= 0) return 0;
            return 1e9;
        }
        
        int t = busyTime + 500;
        if(dp[idx][t] != -1) return dp[idx][t]; 
        
        // I do this job
        int work = v[idx][0] + solve(idx+1, busyTime+v[idx][1], v);
        
        // I don't work
        int no_work = solve(idx+1, busyTime-1, v);
        
        return dp[idx][t] = min(work, no_work);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {  
        int n = cost.size();
        int sum = 0;

        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            sum += time[i];
            v.push_back({cost[i], time[i]});
        }
        
        // sort(v.begin(), v.end());
        
        dp.resize(n+1, vector<int>(sum+510,-1));        
        return solve(0, 0, v);    
    }
};