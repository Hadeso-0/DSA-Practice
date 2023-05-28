class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& st) {
        if(maze[st[0]][st[1]] == '+') return -1;
        
        int n = maze.size();
        int m = maze[0].size();
        int ans = 0;

        queue<vector<int>> q;
        q.push(st);
        maze[st[0]][st[1]] = '+';
        
        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};
        
        while(!q.empty()){
            ++ans;
            for(int i=q.size()-1; i>=0; --i){
                vector<int> tp = q.front();
                q.pop();
                for(int d = 0; d<4; ++d){
                    int x = tp[0] + dx[d];
                    int y = tp[1] + dy[d];
                
                    // check if valid
                    if((x>=0) && (y>=0 )&& (x<n) && (y<m) && (maze[x][y] != '+')){
                        if(x==0 || y==0 || x==n-1 || y==m-1){// if is an exit
                            return ans;
                        }
                        q.push({x,y});
                        maze[x][y] = '+';
                    }
                }
            }
        }
  
        return -1;
    }
};