class Solution {
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> frq;
        int i=0; int j = 0; int ans = 0;
        int n = nums.size();
        while(j < n){
            ++frq[nums[j]];
            while(i <= j && frq.size() > k){
                if(frq[nums[i]] == 1) frq.erase(nums[i]);
                else --frq[nums[i]];
                ++i;
            }
            ans += (j-i+1);
            ++j;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};