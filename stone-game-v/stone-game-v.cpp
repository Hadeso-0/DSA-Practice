class Solution {
    // int solve(vector<int>& pre, int l, int r, vector<vector<int>>& dp){
    //     if(l == r) {
    //         // single element left
    //         // return pre[r]-pre[r-1];
    //         return 0;
    //     }
    //     if(dp[l][r] != -1) return dp[l][r];

    //     int ans = 0;
    //     for(int par=l; par<r; ++par){
    //         // left partititon  = lft   --- par
    //         // right partititon = par+1 --- rgt
    //         int lft_val = (pre[par] - pre[l-1]); 
    //         int lft_sol = dp[l][par]; 
    //         if(lft_sol == -1) lft_sol = solve(pre, l, par, dp); 
            
    //         int rgt_val = (pre[r] - pre[par]); 
    //         int rgt_sol = dp[par+1][r]; 
    //         if(rgt_sol == -1) rgt_sol = solve(pre, par+1, r, dp); 
            
    //         if(lft_val > rgt_val){
    //             ans = max( ans, rgt_val + rgt_sol);
    //         }else if(lft_val < rgt_val){
    //             ans = max( ans, lft_val + lft_sol);
    //         }else{
    //             ans = max(ans, max(lft_val + lft_sol, rgt_val + rgt_sol));
    //         }
    //     }

    //     return dp[l][r] = ans;
    // }
    // int findPart(vector<int>& pre, int l, int r){
    //     int mid = (l+r)/2;
    //     int lft = l;
    //     int ans = l-1;
    //     int sum = pre[r]- pre[l-1];
    //     cout<<"part"<<l<<" "<<r<<" ";
    //     while(l<=r){
    //         mid = (l+r)/2;
    //         // left  sum = pre[mid] - pre[lft-1];
    //         if(2*(pre[mid]-pre[lft-1]) < sum){
    //             l = mid+1;
    //             ans = mid;             
    //         }
    //         else{
    //             r = mid-1;
    //         }
    //     }
    //     cout<<ans<<endl;
    //     return ans;
    // }
    
    int pre[502];
    int dp[502][502];
public:
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        for(int i=1; i<=n; ++i){
            pre[i] = pre[i-1] + stones[i-1];
        }
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // return solve(preSum, 1, n, dp);

        for(int l=n; l>=1; --l){
            dp[l][l] = 0;
            for(int r=l+1; r<=n; ++r){
                for(int par=l; par<r; ++par){
                    // left partititon  = lft   --- par
                    // right partititon = par+1 --- rgt
                    int lft_val = pre[par] - pre[l-1]; 
                    int rgt_val = pre[r] - pre[par];                    
                    if(lft_val > rgt_val){
                        dp[l][r] = max( dp[l][r], rgt_val + dp[par+1][r]);
                    }else if(lft_val < rgt_val){
                        dp[l][r] = max( dp[l][r], lft_val + dp[l][par]);
                    }else{
                        dp[l][r] = max(dp[l][r], max(lft_val + dp[l][par], rgt_val + dp[par+1][r]));
                    }
                }
            }
        }

        return dp[1][n];
    }
};