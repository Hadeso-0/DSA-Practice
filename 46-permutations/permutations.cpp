class Solution {
    void solution(vector<int> nums, vector<vector<int>>& ans, int idx){
        if(idx >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);

            solution(nums, ans, idx+1);

            swap(nums[idx], nums[i]); // backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solution(nums, ans, 0);

        return ans;
    }
};