class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        vector<int> min_cost(nums.size(), INT_MAX);
        vector<int> choc_num(nums.begin(), nums.end());
        
        for(auto n: nums) choc_num.push_back(n);
        long long ans = LONG_MAX;
        for(int i=0; i<nums.size(); ++i){
            long long sum = 0;
            for(int j=0; j<nums.size(); ++j){
                if(min_cost[j] > choc_num[i+j]) 
                min_cost[j] = choc_num[i+j];
                sum += min_cost[j];
            }
            sum += (long long)i*(long long)x;
            if(sum < ans) ans = sum;
        }
        
        return ans;
    }
};