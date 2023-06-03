class Solution {
    void dfs(int i, vector<vector<int>>& rooms, vector<bool>& vis){
        vis[i] = true;
        for(auto& key : rooms[i]){
            if(!vis[key]) dfs(key, rooms, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);

        for(int i=0; i<n; ++i){
            if(!vis[i]) return false;
        }
        return true;
    }
};