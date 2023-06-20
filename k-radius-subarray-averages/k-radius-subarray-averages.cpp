class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> ans(n, -1);
        if(n <= 2*k) return ans;

        long long  sm = 0;
        for(int i=0; i<=2*k; ++i){
            sm += nums[i]*1LL;
        }

        for(int i=k; i+k < n; ++i){
            ans[i] = sm/(2*k+1);
            sm -= nums[i-k]*1LL;
            if(i+k+1 < n) sm += nums[i+k+1]*1LL;
        }

        return ans;
    }
};