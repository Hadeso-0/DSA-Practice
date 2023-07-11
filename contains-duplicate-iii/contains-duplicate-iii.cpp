class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        unordered_map<int,int> bucket;
        for(int i=0; i<n; ++i){
            int bucketNum = nums[i]/(valueDiff+1);
            if(nums[i] < 0) --bucketNum;

            if(bucket.find(bucketNum) != bucket.end()) return true;
            else{
                bucket[bucketNum] = nums[i];
                if((bucket.find(bucketNum-1) != bucket.end()) && ((nums[i] - bucket[bucketNum-1]) <= valueDiff)){
                    return true;
                }
                if((bucket.find(bucketNum+1) != bucket.end()) && ((bucket[bucketNum+1] - nums[i]) <= valueDiff)){
                    return true;
                }
            }
            if(bucket.size() > indexDiff){
                int to_be_rem = nums[i-indexDiff] / (valueDiff+1);
                if(nums[i-indexDiff] < 0) --to_be_rem;

                bucket.erase(to_be_rem);
            }
        }
        return false;
    }
};