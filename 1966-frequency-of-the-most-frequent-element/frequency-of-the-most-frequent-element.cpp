class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 0;
        int n = nums.size();
        long long sm = 0;
        int ans = 0;
        while(r < n){
            sm += nums[r];
            while((r-l+1)*1LL*nums[r] > sm + k){
                sm -= nums[l];
                ++l;
            }
            ans = max(ans, (r-l+1));
            ++r;
        }   
        return ans;
    }
};