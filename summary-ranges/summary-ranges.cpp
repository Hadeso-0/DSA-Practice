class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int str = nums[0];
        int end = nums[0];

        for(int i=1; i<nums.size(); ++i){
            if(nums[i] == nums[i-1]+1){
                end = nums[i];
            }
            else{
                if(str == end){ ans.push_back(to_string(str)); }
                else{ ans.push_back(to_string(str)+"->"+to_string(end)); }
                str = nums[i];
                end = nums[i];
            }
        }
        if(str == end){ ans.push_back(to_string(str)); }
        else{ ans.push_back(to_string(str)+"->"+to_string(end)); }
        return ans;
    }
};