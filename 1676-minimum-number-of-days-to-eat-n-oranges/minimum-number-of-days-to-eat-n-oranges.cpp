class Solution {
    int hades(int n, unordered_map<int, int>& dp){
        if(n == 1) return 1;
        if(n == 0) return 0;
        if(dp.find(n) != dp.end())
            return dp[n];

        int ans = 1 + min((n%2)+hades(n/2, dp), (n%3)+hades(n/3, dp));
        return dp[n] = ans;
    }
public:
    int minDays(int n) {
        unordered_map<int,int> dp;
        return hades(n, dp);
    }
};