class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& temp, int i, int n, int k){
        if(i == k){
            ans.push_back(temp);
            return;
        }

        int pre;
        if(temp.empty()) pre = 0;
        else pre = temp.back();

        for(int j = pre+1; j <= (n-k+1+i); j++){
            temp.push_back(j);
            solve(ans,temp,i+1,n,k);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, 0, n, k);
        return ans;
    }
};