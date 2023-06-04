class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int tmp = 0;
        int win_len = 0;
        int i = 0;
        
        for (int j = 0; j < nums.size(); ++j) {
            if(nums[j] == 0) ++tmp;

            while (tmp > 1) {
                if(nums[i] == 0) --tmp;
                ++i;
            }
              
            win_len = max(win_len, j-i);
        }

        return win_len;
    }
};