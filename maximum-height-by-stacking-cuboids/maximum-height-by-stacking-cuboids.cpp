class Solution {
    bool isOkay(const vector<int>& c1, const vector<int>& c2){
        return (c1[2] <= c2[2])&&(c1[1] <= c2[1]);
    }
    int solve(vector<vector<int>>& arr, int idx, int prev, vector<vector<int>>& dp){
        if(idx == arr.size()) return 0;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];

        int place = 0;
        if(prev == -1 || isOkay(arr[prev], arr[idx])){
            place = arr[idx][2] + solve(arr, idx+1, idx, dp);
        }
        int notPlace = solve(arr, idx+1, prev, dp);

        return dp[idx][prev+1] = max(place, notPlace);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& c : cuboids){
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        // return solve(cuboids, 0, -1);

        for(auto& c: cuboids){
            cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // int ans = 0;
        // int end = 0;
        // for(int i=0; i<n; ++i){
            
        // }
        // return ans;
        return solve(cuboids, 0, -1, dp);
    }
};