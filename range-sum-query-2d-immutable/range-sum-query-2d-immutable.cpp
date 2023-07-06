class NumMatrix {
    vector<vector<int>> pre;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        pre.resize(n+1, vector<int>(m+1, 0));
        for(int i=n-1; i>=0; --i){
            for(int j=m-1; j>=0; --j){
                pre[i][j] = matrix[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i+1][j+1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pre[row1][col1] - pre[row2+1][col1] - pre[row1][col2+1] + pre[row2+1][col2+1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */