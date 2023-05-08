class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<min(n,m); ++i){
            sum += mat[i][i];
            if(i != m-i-1)
                sum += mat[i][m-i-1];
        }
        return sum;
    }
};