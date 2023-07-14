class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        int ans = 1;
        int n = arr.size();

        int k=1e4;
        int dp[2*k+1];
        memset(dp, 0, sizeof(dp));
        // Maps a element in arr to length of longest seq. ending at that value

        for(int i=0; i<n; ++i){
            if((k + arr[i] - dif) < 0 || (k + arr[i] - dif) > 2*k){
                // Its pair does not exist
                dp[k + arr[i]] = 1;
            }
            else{
                dp[k+arr[i]] = dp[k + arr[i] - dif]+1;
                ans = max(ans, dp[k+arr[i]]);
            }
        }
        return ans;
    }
};