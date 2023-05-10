class Solution {
    unordered_map<int,bool> mapRow;
    unordered_map<int,bool> mapDg1;
    unordered_map<int,bool> mapDg2;
    
    bool isPossible(int r, int c){
        if(mapRow[r] || mapDg1[r-c] || mapDg2[r+c]) 
            return false;
        return true;
    }

    int solve(int col, int n){
        if(col == n){
            return 1;
        }

        int ans = 0;
        for(int r= 0; r<n; r++){
            if(isPossible(r,col)){
                mapRow[r] = mapDg1[r-col] = mapDg2[r+col] = true;
                ans += solve(col+1, n);
                mapRow[r] = mapDg1[r-col] = mapDg2[r+col] = false;
            }   
        }

        return ans;
    }
public:
    int totalNQueens(int n) {
        // vector<vector<char>> board(n, vector<char>(n, '.'));
        // int ans = 0;
        return solve(0, n);
    }
};