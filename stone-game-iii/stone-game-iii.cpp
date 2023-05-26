class Solution {
    // int solve(vector<int>& suf, int idx, int n){
    //     if(idx >= n) return 0;

    //     int ans = 1e8;
    //     for(int i=1; i<=3; ++i){
    //         if(idx + i > n) break;
    //         ans = min(ans, solve(suf, idx+i, n));
    //     }
    //     return suf[idx]-ans;
    // }
public:
    string stoneGameIII(vector<int>& stones) {
        int n= stones.size();
        vector<int> suf(n+1, 0);

        for(int i=n-1; i>=0; --i){
            suf[i] = suf[i+1] + stones[i];
        }

        // int score = solve(suf, 0, n);
        // cout<<score;
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; --i){
            int ans = 1e8;
            for(int j=i+1; j<= min(i+3, n); ++j){
                ans = min(ans, dp[j]);
            }
            dp[i] = suf[i]-ans;   
        }

        int score = dp[0];
        if((2*score) > suf[0]){
            return "Alice";
        }else if((2*score) == suf[0]){
            return "Tie";
        }
        return "Bob";
    }
};