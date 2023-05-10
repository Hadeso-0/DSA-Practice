class Solution {
    unordered_map<int,bool> mapRow;
    unordered_map<int,bool> mapDg1;
    unordered_map<int,bool> mapDg2;
    
    bool isPossible(int r, int c){
        if(mapRow.find(r) != mapRow.end()) return false;
        if(mapDg1.find(r-c) != mapDg1.end()) return false;
        if(mapDg2.find(r+c) != mapDg2.end()) return false;
        return true;
    }
    void pushAns(vector<vector<char>>& board, vector<vector<string>>& ans, int n){
        string tmp;
        ans.push_back({});
        for(int i=0; i<n; i++){
            tmp = "";
            for(int j=0; j<n; j++) tmp.push_back(board[i][j]);
            (ans.back()).push_back(tmp);
        }
    }
    void solve(int col, vector<vector<char>>& board, int n, vector<vector<string>>& ans){
        if(col == n){
            pushAns(board, ans, n);
            return;
        }

        for(int r= 0; r<n; r++){
            if(isPossible(r,col)){
                board[r][col] = 'Q';
                mapRow[r] = true;
                mapDg1[r-col] = true;
                mapDg2[r+col] = true;

                solve(col+1, board, n, ans);

                board[r][col] = '.';
                mapRow.erase(r);
                mapDg1.erase(r-col);
                mapDg2.erase(r+col);
            }   
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        solve(0, board, n, ans);
        return ans;
    }
};