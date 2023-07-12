class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ind(n, 0);
        vector<vector<int>> revGraph(n);
        for(int i=0; i<n; ++i){
            for(int& nex : graph[i]){
                revGraph[nex].push_back(i);
                ++ind[i];
            }
        }

        queue<int> q;
        for(int i=0; i<n; ++i){
            if(ind[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int fr = q.front(); q.pop();
            ans.push_back(fr);
            for(auto& ch : revGraph[fr]){
                --ind[ch];
                if(ind[ch] == 0){
                    q.push(ch);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};