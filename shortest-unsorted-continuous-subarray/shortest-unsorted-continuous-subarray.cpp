class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Naive Approach
        vector<int> clone_nums = nums;
        sort(clone_nums.begin(), clone_nums.end());

        int left = 0;
        int right = nums.size() -1;
        while(left < nums.size() && nums[left] == clone_nums[left]) ++left; 
        while(right >= 0 && nums[right] == clone_nums[right]) --right;
        return max(0, right-left+1); 
    }
};