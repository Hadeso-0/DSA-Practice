class Solution {
    int dp[101][101];
    int hades(int l, int r, string& s){
        if(dp[l][r] != -1){
            return dp[l][r];
        }

        dp[l][r] = s.size();
        int j = -1;

        for(int i=l; i<r; ++i){
            if(s[i] != s[r] && j==-1){
                j = i;
            }

            if(j != -1){
                dp[l][r] = min(dp[l][r], 1+hades(j,i, s) + hades(i+1, r, s));
            }
        }

        if(j == -1){
            dp[l][r] = 0;
        }
        return dp[l][r];
    }
public:
    int strangePrinter(string s) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        return hades(0, s.size()-1, s) + 1;
    }
};