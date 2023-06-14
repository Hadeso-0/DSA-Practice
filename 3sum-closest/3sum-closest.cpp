class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int ans = 0; int min_diff = INT_MAX;
        for(int i=0; i<nums.size()-2; ++i){
            int j= i+1;
            int k = nums.size()-1;
            while(j < k){
                int cur_sum = nums[i]+nums[j]+nums[k];
                int diff = abs(target - cur_sum);

                if(diff == 0) return cur_sum;
                if(diff < min_diff){
                    min_diff = diff;
                    ans = cur_sum;
                }
                if(cur_sum > target){
                    --k;
                }
                else{
                    ++j;
                }
            }
        }
        return ans;
    }
};