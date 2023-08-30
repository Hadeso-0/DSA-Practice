class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i=n-2; i>=0; --i){
            if(nums[i] <= nums[i+1]){
                continue;
            }
            else{
                long long tmp = ceil((nums[i] + nums[i+1] - 1LL) / nums[i+1]);
                ans = ans + tmp - 1;

                nums[i] = (nums[i] / tmp);
            }
        }
        return ans;
    }
};