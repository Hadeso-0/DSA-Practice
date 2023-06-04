class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sm = 0;
        for(int i=0; i<k; ++i) sm += nums[i];
        double ans = (double)sm/k;

        for(int i=k; i<nums.size(); ++i){
            sm -= nums[i-k];
            sm += nums[i];
            ans = max(ans, (double)sm/k);
        }
        return ans;
    }
};