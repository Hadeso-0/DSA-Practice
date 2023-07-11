class Solution {
public:
    int minOperations(vector<int>& nums) {
        int max_til = nums[0];

        int ans = 0;
        for(int i=1; i<nums.size();++i){
            if(nums[i] <= max_til){
                ++max_til;
                ans += (max_til - nums[i]);
            }
            else{
                max_til = nums[i];
            }
        }
        return ans;
    }
};