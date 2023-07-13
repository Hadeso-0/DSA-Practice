class Solution {
    int solve(int idx, int d, vector<int>& jobs, vector<vector<int>>& dp){
        if(d == 1){
            int tmp = *max_element(jobs.begin()+idx, jobs.end());
            // cout<<tmp<<endl;
            return tmp;
        }

        if(dp[idx][d] != -1) return dp[idx][d]; 

        int max_diff = jobs[idx];
        int ans = INT_MAX;
        
        for(int k = idx; k<=(jobs.size()-d); ++k){
            max_diff = max(max_diff, jobs[k]);
            int temp = max_diff + solve(k+1, d-1, jobs, dp);
            // cout<<max_diff<<","<<temp<<" ";
            ans = min(ans, temp);
        }
        return dp[idx][d] = ans;
    }
public:
    int minDifficulty(vector<int>& jobs, int d) {
        if(d > jobs.size()) return -1;
        if(d == jobs.size()){
            int sum = 0; 
            for(int i=0; i<jobs.size(); ++i) sum+=jobs[i];
            return sum;
        }

        vector<vector<int>> dp(jobs.size()+1, vector<int>(d+1, -1));
        return solve(0, d, jobs, dp);
    }
};