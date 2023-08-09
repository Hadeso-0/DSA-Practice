class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> temp = {1};
        vector<vector<int>> ans;
        ans.push_back(temp);

        if(n == 1) return ans;
        for(int i=2; i<=n; ++i){
            for(int j=temp.size()-1; j>=1; --j){
                temp[j] += temp[j-1];
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};