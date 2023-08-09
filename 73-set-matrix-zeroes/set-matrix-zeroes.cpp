class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int fr = 1; int fc = 1;
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0; i<n; ++i){
            if(matrix[i][0] == 0){
                fc = 0; break;
            }
        }
        for(int j=0; j<m; ++j){
            if(matrix[0][j] == 0){
                fr = 0; break;
            }
        }

        for(int i=1;i<n;++i){
            for(int j=1; j<m; ++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;++i){
            for(int j=1; j<m; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(fc == 0){
            for(int i=0; i<n; ++i){
                matrix[i][0] = 0;
            }
        }
        if(fr == 0){
            for(int j=0; j<m; ++j){
                matrix[0][j] = 0;
            }
        }
    }
};