class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> diags;
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[0].size(); ++j){
                diags[i+j].push_back(mat[i][j]);
            }
        }   
        vector<int> ans;
        for(auto& dg : diags){
            if(dg.first%2 == 0) reverse(dg.second.begin(), dg.second.end());
            for(auto& x : dg.second) 
                ans.push_back(x);
        }
        return ans;
    }
};