class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        vector<int> ans;

        while(l < r){
            if(nums[l] + nums[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                return ans;
            }
            else if(nums[l] + nums[r] > target){
                --r;
            }
            else{
                ++l;
            }
        } 
        return ans;
    }
};