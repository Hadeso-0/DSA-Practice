class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> vals;
        for(int i=0; i<n;++i){
            if(vals.size() > indexDiff) vals.erase(vals.find(nums[i - indexDiff-1]));
            // 
            auto left = vals.lower_bound(nums[i] - valueDiff);
            if((left != vals.end()) && (abs(*(left) - nums[i]) <= valueDiff)) return true;
                
            auto right = vals.upper_bound(nums[i] + valueDiff);
            if((right != vals.begin()) && (abs(*prev(right) - nums[i]) <= valueDiff)) return true;

            vals.insert(nums[i]);
        }
        return false;
    }
};