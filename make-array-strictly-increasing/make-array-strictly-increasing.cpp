class Solution {
    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2, vector<map<int,int>>& dp){
        if(i == arr1.size()) return 0;
        
        if(dp[i].find(prev) != dp[i].end()) return dp[i][prev];

        int ops1 = 1e8;
        if(arr1[i] > prev){
            ops1 = solve(i+1, arr1[i], arr1, arr2, dp);
        }

        int idx = lower_bound(arr2.begin(), arr2.end(), prev+1) - arr2.begin();
        if(idx < arr2.size()){
            ops1 = min(ops1, 1 + solve(i+1, arr2[idx], arr1, arr2, dp));
        }

        return dp[i][prev] = ops1;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> s(arr2.begin(), arr2.end());
        arr2.resize(s.size());
        int i=0;
        for(auto& it : s){
            arr2[i++] = it;
        } 
        vector<map<int,int>> dp(arr1.size());
      
        int ans = solve(0,-1,arr1,arr2, dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};