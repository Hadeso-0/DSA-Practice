class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // O(n)
        // for(int i=0; i<nums.size(); ++i){
        //     if(nums[i] == target) return true;
        // }
        // return false;

        // O(log(n))
        int l = 0;
        int r = nums.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(target == nums[mid]){
                return true;
            }
            if(nums[mid] == nums[l]){
                ++l;
                continue;
            }
            
            bool isTargetInF = target >= nums[l];
            bool isMidInF = nums[mid] >= nums[l];

            if(isTargetInF ^ isMidInF){
                if(isMidInF){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(nums[mid] > target){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return false;
    }
};