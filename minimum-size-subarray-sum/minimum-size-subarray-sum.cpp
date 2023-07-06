class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 1e8;
        int cur_sum = 0;

        while(j < n){
            cur_sum += nums[j];

            if(cur_sum < target) ++j;
            else{
                while(cur_sum >= target){
                    len = min(len, j-i+1);
                    cur_sum -= nums[i];
                    ++i;
                }
                ++j;
            }
        }
        if(len == 1e8) return 0;
        return len;        
    }
};