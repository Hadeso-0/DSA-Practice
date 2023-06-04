class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> zers;
        int n = nums.size();
        zers.push_back(-1);
        for(int i=0; i<n; ++i) if(nums[i] == 0) zers.push_back(i);
        zers.push_back(n);

        if(zers.size() == 2) return n-1;
        int ans = 0;
        for(int i=1; i<zers.size()-1; ++i){
            ans = max(ans, zers[i+1]-zers[i-1]-2);
        }
        return ans;
    }
};