class Solution {
    bool solve(int i, int j, vector<vector<char>>& board, int n, int sqrt_n, vector<vector<bool>>& row_mp
                , vector<vector<bool>>& col_mp, vector<vector<bool>>& box_mp ){
        if(i>=n || j>=n) 
            return true;

        // cout<<i<<" "<<j<<endl;
        bool flg = false;
        if(board[i][j] == '.'){
            for(int v=1; v<=n; v++){
                if(row_mp[i][v] || col_mp[j][v] || box_mp[((i/sqrt_n)*sqrt_n) + (j/sqrt_n)][v] ) 
                    continue;
                else{
                    board[i][j] = v + '0';
                    row_mp[i][v] = true;
                    col_mp[j][v] = true; 
                    box_mp[((i/sqrt_n)*sqrt_n) + (j/sqrt_n)][v] = true;
                    if(j == n-1){
                        flg = solve(i+1, 0, board, n, sqrt_n, row_mp, col_mp, box_mp);
                    }
                    else{
                        flg = solve(i, j+1, board, n, sqrt_n, row_mp, col_mp, box_mp);
                    }
                    if(flg) return true;
                    row_mp[i][v] = false;
                    col_mp[j][v] = false; 
                    box_mp[((i/sqrt_n)*sqrt_n) + (j/sqrt_n)][v] = false;
                    board[i][j] = '.';
                }
            }
        }
        else{
            if(j == n-1){
                flg = solve(i+1, 0, board, n, sqrt_n, row_mp, col_mp, box_mp);
            }
            else{
                flg = solve(i, j+1, board, n, sqrt_n, row_mp, col_mp, box_mp);
            }
            if(flg) return true;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size(); // n==9
        int sqrt_n = sqrt(n); // sqrt_n==3
        vector<vector<bool>> row_map(n+1,vector<bool>(n+1,false));
        vector<vector<bool>> col_map(n+1,vector<bool>(n+1,false));
        vector<vector<bool>> box_map(n+1,vector<bool>(n+1,false));
        
        int x;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    x = board[i][j]-'0';
                    row_map[i][x] = true;
                    col_map[j][x] = true;
                    box_map[((i/sqrt_n)*sqrt_n) +( j/sqrt_n)][x] = true;
                }
            }
        }

        solve(0,0,board, n, sqrt_n, row_map, col_map, box_map);
    }
};