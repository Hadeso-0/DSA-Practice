class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> ways(n,1);
        int max_len = 0;
        for(int i=0; i<n; ++i){
            dp[i] = 1;
            for(int j=0; j<i; ++j){
                if(nums[i] > nums[j]){ 
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1+dp[j];
                        ways[i] = ways[j];    
                    }
                    else if(dp[i] == 1+dp[j]){
                        ways[i] += ways[j];
                    }
                }
            }
            max_len = max(max_len, dp[i]);
        }
        for(auto& i : dp) cout<<i<<" ";
        cout<<endl;
        for(auto& i : ways) cout<<i<<" ";
        int ans = 0;
        for(int i=0; i<n; ++i) if(dp[i] == max_len) ans+=ways[i];
        return ans;
    }
};