class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n, 0));
        int row_s = 0;         
        int col_s = 0;         
        int row_e = n-1;         
        int col_e = n-1;

        int num = 0;
        while(n > 0){
            for(int i = col_s; i<=col_e; ++i) ans[row_s][i] = ++num;
            ++row_s;
            for(int i = row_s; i<=row_e; ++i) ans[i][col_e] = ++num;
            --col_e;
            for(int i = col_e; i>=col_s; --i) ans[row_e][i] = ++num;
            --row_e;
            for(int i = row_e; i>=row_s; --i) ans[i][col_s] = ++num;
            ++col_s;
            n = n-2;
        }         
        return ans;
    }
};