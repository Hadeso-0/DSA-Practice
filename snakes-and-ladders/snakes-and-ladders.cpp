class Solution {
    int genVal( int i, int j, int n){
        i = n-1-i;
        if(i%2 == 1) j = n-1-j;
        return ((n*i) + j + 1);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n =  board.size();


        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] != -1){
                    int src = genVal(i,j,n);
                    mp[src] = board[i][j];
                }
            }
        }  

        queue<int> q;
        q.push(1);
        vector<bool> vis((n*n)+1, false);
        vis[1] = true;
        int ans = 0;

        while(!q.empty()){
            ++ans;
            for(int i=q.size()-1; i>=0; --i){
                int cur = q.front();
                // cout<<cur<<" ";
                q.pop();

                for(int i=1; i<=6; ++i){
                    int nex = cur + i;

                    if(mp[nex] != 0) nex = mp[nex];

                    if(nex == (n*n)) return ans; 
                    if(vis[nex]) continue;
                    q.push(nex);
                    vis[nex] = true;
                }
            }
            // cout<<endl;
        }
        return -1;
    }
};