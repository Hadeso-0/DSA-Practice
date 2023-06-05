class Solution {
    int solve(int s, int e, vector<int>& nums, vector<vector<int>>& dp){
        if(s > e) return 0;
        if(s == e){ return nums[s-1]*nums[s]*nums[s+1]; }
        if(dp[s][e] != -1) return dp[s][e];

        int ans = 0;
        for(int k = s; k<=e; ++k){
            int temp = solve(s,k-1, nums, dp) + solve(k+1,e, nums, dp) + nums[s-1]*nums[k]*nums[e+1]; 
            ans = max(ans, temp);
        }
        return dp[s][e] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(auto& x : nums) arr.push_back(x);
        arr.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        int ans = solve(1, n, arr, dp);
        
        for(auto& i : dp){
            for(auto& j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};