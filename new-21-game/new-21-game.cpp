class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // vector<double> dp(n+1, 0);
        // dp[1] = (double)
        // max achieveable points (k-1 + maxPts);
        if(n >= k+maxPts-1) return (double)1.00000;

        vector<double> dp(n+1,0);
        dp[0] = (double)1.00000;
        double sm = k>0 ? 1 : 0;

        // cout<<dp[1]<<endl;
        for(int i=1; i<=n; ++i){
            dp[i] = (sm/maxPts);
            if(i<k){
                sm += dp[i];
            }
            if(i-maxPts >= 0 && i-maxPts < k){
                sm -= dp[i-maxPts];
            }
        }

        double ans = 0;
        for(int i=k; i<=n; ++i){
            cout<<dp[i]<<" ";
            ans += dp[i];
        }
        
        return ans;
    }
};