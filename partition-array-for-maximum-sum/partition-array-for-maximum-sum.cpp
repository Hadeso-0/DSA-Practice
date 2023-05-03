class Solution {
    // int solve(vector<int>& arr, int k, int idx, vector<int>& dp){
    //     if(idx >= arr.size()){
    //         return 0;
    //     }
    //     if(dp[idx] != -1)return dp[idx];
    //     int ans = 0;
    //     int maxi = 0; 
    //     int i;
    //     for(i = idx; i<min((int)arr.size(), idx+k); i++){
    //         maxi = max(maxi, arr[i]);
    //         int x = dp[i+1];
    //         if(x==-1) x = solve(arr, k, i+1,dp);

    //         int temp = (maxi*(i-idx+1)) + x;
    //         ans = max(ans, temp);
    //     }
    //     return dp[idx] = ans;
    // }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1, 0);
        // return solve(arr, k, 0, dp);
        for(int i=arr.size()-1; i>=0; i--){
            int maxi = -1;
            int ans = -1;
            for(int j = i; j<min((int)arr.size(), i+k); j++){
                maxi = max(maxi, arr[j]);
                ans = max(ans, (maxi*(j-i+1)) + dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};