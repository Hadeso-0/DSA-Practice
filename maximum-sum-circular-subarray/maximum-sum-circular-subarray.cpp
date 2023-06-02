class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int lmax=0,gmax=INT_MIN;
        int lmin=0,gmin=INT_MAX;
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;++i){
            lmax=max(nums[i]+lmax,nums[i]);
            gmax=max(gmax,lmax);
            lmin=min(nums[i]+lmin,nums[i]);
            gmin=min(gmin,lmin);
        }
        return gmax < 0 ? gmax : max(gmax,total_sum-gmin);
    }
};