class Solution {
    bool dfs(string& ans,  unordered_set<string>& vis, int n, int k){
        if(vis.size() == (int)pow(k,n)) 
            return true;

        string comm = ans.substr(ans.size() - n + 1);
        for(int j=0; j<k; ++j){
            string nex = comm + to_string(j);
            if(vis.find(nex) != vis.end()) continue;
            
            vis.insert(nex);
            ans = ans + to_string(j);
            
            if(dfs(ans, vis, n, k)) return true;
            
            vis.erase(nex);
            ans.pop_back();
        }
        return false;
    }
public:
    string crackSafe(int n, int k) {
        string start = "";
        for(int i=0; i<n; ++i) start += "0";
        unordered_set<string> vis;
        vis.insert(start);
        
        string ans = start; 
        dfs(ans, vis , n, k);
        return ans;
    }
};