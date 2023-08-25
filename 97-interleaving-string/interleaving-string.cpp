class Solution {
    // bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
    //     if(i == s1.size()){
    //         return s2.substr(j) == s3.substr(k);
    //     }
    //     if(j == s2.size()){
    //         return s1.substr(i) == s3.substr(k);
    //     }

    //     if(dp[i][j] != -1) return dp[i][j];

    //     bool ans= false;
    //     ans = ans || ((s1[i] == s3[k]) && (solve(i+1,j,k+1,s1,s2,s3, dp))); 
    //     ans = ans || ((s2[j] == s3[k]) && (solve(i,j+1,k+1,s1,s2,s3, dp))); 
    //     return dp[i][j] = ans;
    // }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // if s3.size() == s1.size() + s2.size()
        // Check if lcs of s1 in s3 is equal to s1
        // if YES -> remove those characters and check if remaining string is equal to s2
        // else NO -> not possible
        int n = s1.size();
        int m = s2.size();
        if(s3.size() != n+m) return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
        // return solve(0,0,0,s1,s2,s3, dp);

        for(int j=m-1, k=s3.size()-1; j>=0; --j, --k){
            if(s2[j] == s3[k]){
                dp[n][j] = true;
            }
            else{
                break;
            }
        }
        dp[n][m] = true;

        for(int i=n-1, k=s3.size()-1; i>=0; --i, --k){
            if(s1[i] == s3[k]){
                dp[i][m] = true;
            }
            else{
                break;
            }
        }

        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                dp[i][j] = dp[i][j] || ((s1[i] == s3[i+j]) && dp[i+1][j]); 
                dp[i][j] = dp[i][j] || ((s2[j] == s3[i+j]) && dp[i][j+1]); 
            }
        }
        return dp[0][0];
    }
};