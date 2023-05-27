class Solution {
    int solve(int i, string s, int j, string t, vector<vector<int>>& dp){ 
        // return the number of ways substr t[j:] can be formed from s[i:]
        
        // Base case -> if(length of s < length of t) -> 0
        // Base case -> if(length of s == length of t) -> return s == t
        int leng_s = s.size() - i;
        int leng_t = t.size() - j;
        if(leng_t == 0) return 1;
        if(leng_s < leng_t) return 0;
        if(leng_s == leng_t) return s.substr(i) == t.substr(j);
        
        // cout<<i<<" "<<j<<endl;
        if(dp[i][j] != -1) return dp[i][j];
        // i can include this index of s if s[i] == t[j]
        int incl = 0;
        if(s[i] == t[j]){
            incl = solve(i+1, s, j+1, t, dp);
        }
        int excl = solve(i+1, s, j, t, dp);

        return dp[i][j] = (incl + excl);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solve(0,s,0,t, dp);
    }
};