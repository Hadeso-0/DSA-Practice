class Solution {
    int genVal( int i, int j, int n){
        i = n-1-i;
        if(i%2 == 1) j = n-1-j;
        return ((n*i) + j + 1);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n =  board.size();
        // vector<vector<int>> brd((n*n)+1);
        // for(int i=1; i<=(n*n); ++i){
        //     for(int j=1; j<=6; ++j){
        //         if(i+j > (n*n)) break;
        //         brd[i].push_back(i+j);
        //     }
        // }

        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != -1){
                    int src = genVal(i,j,n);
                    // cout<<src<<"->"<<board[i][j]<<endl;
                    mp[src] = board[i][j];
                }
            }
        }  

        queue<pair<int,int>> q;
        q.push({1, 0});
        vector<bool> vis((n*n)+1, false);
        vis[1] = true;
        while(!q.empty()){
            int cur = q.front().first;
            int moves = q.front().second;
            // cout<<cur<<"("<<moves<<")"<<"-> ";
            q.pop();
            for(int i=1; i<=6; ++i){
                int nex = cur + i;

                if(mp[nex] != 0) nex = mp[nex];
                if(vis[nex]) continue;
                // cout<<nex<<", ";
                if(nex == (n*n)) return (moves+1);
                q.push({nex, moves+1});
                vis[nex] = true;
            }
            // cout<<endl;
        }
        return -1;
    }
};