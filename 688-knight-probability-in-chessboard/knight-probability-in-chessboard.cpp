class Solution {
    const vector<vector<int>> dirs = {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(30, vector<double>(30, 0.0));
        dp[row][column] = (double)1;

        for(int move = 1; move <= k; ++move){
            vector<vector<double>> nex_state(30, vector<double>(30, 0.0));
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    for(auto& d : dirs){
                        int i_nex = i + d[0]; int j_nex = j+d[1];
                        if((i_nex >= 0) && (i_nex < n) && (j_nex < n) && (j_nex >= 0)){
                            nex_state[i][j] += (double)dp[i+d[0]][j+d[1]]/(double)8;
                        }
                    }
                }
            }
            dp = nex_state;
        }
        
        double ans = (double)0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ans = ans + (double)dp[i][j];
            }
        }
        return ans;
    }
};