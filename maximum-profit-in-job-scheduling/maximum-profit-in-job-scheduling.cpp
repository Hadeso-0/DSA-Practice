class Solution {
    int solve(int idx, int cur_time, vector<vector<int>>& jobs, vector<int>& dp){
        if(idx == jobs.size()) return 0;
        
        if(jobs[idx][0] < cur_time){
            return solve(idx+1, cur_time, jobs, dp);
        }

        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(solve(idx+1, cur_time, jobs, dp), jobs[idx][2] + solve(idx+1, jobs[idx][1], jobs, dp));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        int max_endTime = INT_MIN;
        for(int i=0; i<n; ++i){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
            max_endTime = max(max_endTime, endTime[i]);
        }

        sort(jobs.begin(), jobs.end());
        vector<int>dp (n+1, -1);

        return solve(0, 0, jobs, dp);
    }
};