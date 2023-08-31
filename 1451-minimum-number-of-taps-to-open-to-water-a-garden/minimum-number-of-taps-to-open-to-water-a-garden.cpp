class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // int ans = 1e9;
        // vector<int> dp(n+1, ans);

        // dp[0] = 0;
        // for(int i=0; i<=n; ++i){
        //     int st = max(0, i-ranges[i]);
        //     int et = min(n, i+ranges[i]);
        //     for(int j = st; j<=et; ++j){
        //         dp[et] = min(dp[et], dp[j]+1); 
        //     }
        // }

        // if(dp[n] == ans) return -1;
        // return dp[n];
        vector<int> maxRch(n+1, 0);

        for(int i=0; i<ranges.size(); ++i){
            int st = max(0, i-ranges[i]);
            int en = min(n, i+ranges[i]);

            maxRch[st] = max(maxRch[st], en);
        }

        int ans = 0;
        int curEnd = 0; int nextEnd = 0;

        for(int i=0; i<=n; ++i){
            if(i > nextEnd) return -1;
            if(i > curEnd){ ++ans; curEnd = nextEnd; }
            nextEnd = max(nextEnd, maxRch[i]);
        }

        return ans;
    }
};