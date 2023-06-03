class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> g(n);
        for(int i=0 ;i<n; ++i){
            if(manager[i] == -1) continue;
            else g[manager[i]].push_back(i);
        }   
        
        queue<pair<int,int>> q;
        q.push({headID, 0});
        int ans = 0;
        while(!q.empty()){
            pair<int,int> fr = q.front();
            q.pop();
            for(auto& subOrd : g[fr.first]){
                int tm = fr.second + informTime[fr.first];
                ans = max(ans, tm);
                q.push({subOrd, tm});
            }
        }
        return ans;
    }
};