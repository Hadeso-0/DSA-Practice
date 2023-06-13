class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        // if(nums[l] > nums[r]) return BSearch_mod(nums, l, r, target);
        // return BSearch(nums, l, r, target);
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[l]){
                // left part sorted
                if(target<nums[l] || target>nums[mid]){
                    l = mid + 1; // present in right sub Array
                }
                else{
                    r = mid-1; // present in left subArray
                }
            }
            else{
                // right part sorted
                if(target>=nums[mid] && target<=nums[r]){
                    l = mid + 1; // present in right sub Array
                }
                else{
                    r = mid-1; // present in left subArray
                }
            }
        }
        return -1;
    }
};