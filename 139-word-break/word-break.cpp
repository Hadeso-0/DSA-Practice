class Solution {
    unordered_map<string, bool> mp;
    bool solve(int i, int j, string s, vector<int>& dp){
        if(i==j){
            return dp[i] = mp[s.substr(i,1)];
        }
        if(dp[i]!= -1)
            return dp[i];

        bool ans = false;
        for(int k=i+1; k<=j; k++){
            if(mp[s.substr(i, k-i)]){
                ans = dp[k]==-1 ? solve(k,j,s,dp): dp[k];
            }
            if(ans) return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word : wordDict){
            mp[word] = true;
        }
        mp[""] = true;
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0, n, s, dp);
    }
};