class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        int row_s = 0;
        int row_e = matrix.size()-1;
        int col_s = 0;
        int col_e = matrix[0].size()-1;

        while(row_s <= row_e && col_s <= col_e){
            // top row
            for(int i=col_s; i<=col_e; i++){
                ans.push_back(matrix[row_s][i]);
            }
            row_s++;

            // rgt col
            for(int i=row_s; i<=row_e; i++){
                ans.push_back(matrix[i][col_e]);
            }
            col_e--;

            // bot row
            if(row_s<=row_e)
                for(int i=col_e; i>=col_s; i--){
                    ans.push_back(matrix[row_e][i]);
                }
            row_e--;

            // lft col
            if(col_s<=col_e)
                for(int i=row_e; i>=row_s ; i--){
                    ans.push_back(matrix[i][col_s]);
                }
            col_s++;
        }
        return ans;

// -------------------------------------------------
        // vector<int> ans;
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        // int rounds = (min(rows, cols)+1)/2;

        // int rnd = 0;
        // int top,rgt,bot,lft; 

        // while(rnd < rounds){
        //     // bounds-
        //     top = rnd;
        //     rgt = cols-rnd-1; 
        //     bot = rows-rnd-1;
        //     lft = rnd; 

        //     // top row
        //     for(int i=lft; i<=rgt; i++){
        //         // cout<<matrix[top][i];
        //         ans.push_back(matrix[top][i]);
        //     }
        //     // rgt col
        //     for(int i=top+1; i<bot; i++){
        //         // cout<<matrix[i][rgt];
        //         ans.push_back(matrix[i][rgt]);
        //     }
        //     // bot row
        //     if(top != bot)
        //         for(int i=rgt; i>=lft; i--){
        //             // cout<<matrix[bot][i];
        //             ans.push_back(matrix[bot][i]);
        //         }
        //     // lft col
        //     if(lft != rgt)
        //         for(int i=bot-1; i>top; i--){
        //             // cout<<matrix[i][lft];
        //             ans.push_back(matrix[i][lft]);
        //         }
            
        //     rnd++;
        // }   

        // return ans;      
    }
};