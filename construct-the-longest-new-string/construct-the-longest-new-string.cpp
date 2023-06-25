class Solution {
    int dp[51][51][51][4] = {};
    int solve(int prev, int x, int y, int z){
        if(dp[x][y][z][prev] != -1) return dp[x][y][z][prev];

        int ans = 0;
        if(x>0 && prev != 1) ans = max(ans, solve(1,x-1,y,z)+2);
        if(y>0 && prev <= 1) ans = max(ans, solve(2,x,y-1,z)+2);
        if(z>0 && prev != 1) ans = max(ans, solve(3,x,y,z-1)+2);

        return dp[x][y][z][prev] = ans;
    }
public:
    int longestString(int x, int y, int z) {
        memset(dp,-1,sizeof(dp));
        return solve(0, x, y, z);
    }
};