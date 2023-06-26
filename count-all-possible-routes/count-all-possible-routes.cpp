class Solution {
    const int mod = 1000000007;
    int solve(vector<int>& locs, int cur, int fuelLeft, int end, vector<vector<int>>& dp){
        if(fuelLeft < 0) return 0;
        if(dp[cur][fuelLeft] != -1) return dp[cur][fuelLeft];

        if(cur == end){
            dp[cur][fuelLeft] = 1;
        }else{
            dp[cur][fuelLeft] = 0;
        }

        for(int next=0; next<locs.size(); ++next){
            if((next != cur) && (fuelLeft >= abs(locs[cur] - locs[next]))){
                dp[cur][fuelLeft] = (dp[cur][fuelLeft] + solve(locs, next, fuelLeft-abs(locs[cur] - locs[next]), end, dp))%mod;
            }
        }

        return dp[cur][fuelLeft];
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();    

        vector<vector<int>> dp(n, vector<int>(fuel + 1, -1));
        return solve(locations, start, fuel, finish, dp);
        // for (int f = 0; f <= fuel; f++) {
        //     dp[finish][f] = 1;
        // }
        
        // for (int f = 0; f <= fuel; f++) {
        //     for (int city = 0; city < n; city++) {            
        //         for (int nextCity = 0; nextCity < n; nextCity++) {               
        //             if (nextCity != city && f >= abs(locations[nextCity] - locations[city])) {
        //                 dp[city][f] = (dp[city][f] + dp[nextCity][f - abs(locations[nextCity] - locations[city])]) % MOD;
        //             }
        //         }
        //     }            
        // }
        // return dp[start][fuel];

    }
};