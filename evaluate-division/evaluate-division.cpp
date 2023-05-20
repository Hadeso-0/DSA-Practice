class Solution {
    double dfs(string par, string src, string tar, unordered_map<string, vector<pair<string,double>>>& g, double temp){
        if(src == tar) return temp;

        // vis[src] = true;
        double ans = temp;
        bool flg = true;
        for(auto& num : g[src]){
            if(num.first == par) continue;

            ans = dfs(src, num.first, tar, g, temp*num.second);
            if(ans != 0){
                flg = false;
                break;
            }
        }
        // vis[src] = false;
        if(flg) return 0.00000;
        return ans;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string,double>>> g;
        for(int i=0; i<equations.size(); i++){
            g[equations[i][1]].push_back({equations[i][0], (double)values[i]});
            g[equations[i][0]].push_back({equations[i][1], (double)(1.00000/values[i])});
        }

        for(auto& i : g){
            cout<<i.first<<" -> ";
            for(auto& j : i.second){
                cout<<"("<<j.first<<","<<(double)j.second<<"), ";
            }
            cout<<endl;
        }
        vector<double> ans;
        // unordered_map<string, bool> vis;
        for(auto& q :queries){
            if(g.find(q[1]) == g.end() || g.find(q[0]) == g.end()){
                ans.push_back(-1.00000);
            }
            else{
                double temp = dfs("#", q[1], q[0], g, 1.00000);
                if(temp <= 0.00000) 
                    ans.push_back(-1.00000);
                else
                    ans.push_back(temp);
            }
        }
        return ans;
    }
};