class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            int r = (q.front()).first;
            int c = (q.front()).second;
            q.pop(); ans.push_back(nums[r][c]);
            if(c == 0 && r+1 < nums.size()) q.push({r+1,0});
            if(c+1 < nums[r].size()) q.push({r,c+1});
        }
        return ans;
    }
};