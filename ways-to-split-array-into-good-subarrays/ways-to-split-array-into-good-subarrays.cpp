class Solution {
    int mod = 1e9+7;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        vector<int> logOnes;
        long long int ans = 1;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] == 1) logOnes.push_back(i);
        }
        if(logOnes.size() == 0) return 0;
         
        for(int i=0; i<logOnes.size()-1; ++i){
            ans = (ans * (logOnes[i+1]-logOnes[i]))%mod;
        }
        return ans;
    }
};