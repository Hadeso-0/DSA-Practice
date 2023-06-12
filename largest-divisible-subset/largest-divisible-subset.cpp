class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prev(n);
        int len = 1;
        int end = 0;

        for(int i = 0; i<nums.size(); ++i){
            prev[i] = i;
            dp[i] = 1;
            // cout<<i<<" ";
            for(int j=0; j<i; ++j){
                if((nums[i] % nums[j]) == 0){
                    // cout<<j<<",";
                    if(dp[i] <= dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev[i] = j;
                        if(dp[i] > len){
                            len = dp[i];
                            end = i;
                        }
                    }
                }
            }
            // cout<<endl;
        } 

        vector<int> ans;
        while(1){
            ans.push_back(nums[end]);
            if(end == prev[end]) break;
            end = prev[end];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};